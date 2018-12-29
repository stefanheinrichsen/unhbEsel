int getFileFrames(char* file) {
  File f = SPIFFS.open(file, "r");
  String line;
  int n = -1;
  int result;
  
  if (!f) {
    Serial.println("Cannot open file!");
    return -1;
  } else {
      Serial.println("Reading file and trying to find frame counter...");
      
      while(f.available() && n<0) {
        line = f.readStringUntil('\n');
        n = line.lastIndexOf("FRAME_COUNT");
      }
      Serial.println("Frame Counter found at this line:");
      Serial.println(line);
      String strFrameNumber = line.substring(n+12);
      result = strFrameNumber.toInt();
  }
  f.close();
  return result;
}

void playFile(char* file, int framespeed) {
  int frameNumber = getFileFrames(file);
  int n = -1;
  RgbColor *anim[64];;
  //uint8_t anim[frameNumber][64*3];

  File f = SPIFFS.open(file, "r");
  String line;
  char rgbChar[8];

  // load file into array
  if (!f) {
    Serial.println("Cannot open file!");
    return;
  } else {
      // forward to first hex number
      while(f.available() && n<0) {
        line = f.readStringUntil('\n');
        n = line.lastIndexOf("0x");
      }
      for(int frame=0; frame<frameNumber; frame++) {
        for(int j=0; j<8; j++) {
          for(int i=0; i<8; i++) {
            String rgbStr=line.substring(4+i*12,4+i*12+6);
            uint32_t rgb = strtol(rgbStr.c_str(), NULL, 16);
            anim[i*8+j] = new RgbColor(rgb & 0xFF, rgb>>8 & 0xFF, rgb>>16);
            strip.SetPixelColor( i*8+j     , *anim[i*8+j]);
            strip.SetPixelColor( 64+i*8+j  , *anim[i*8+j]);
          }
        line = f.readStringUntil('\n');
      }
      strip.Show();
      delay(framespeed);
      line = f.readStringUntil('\n'); line = f.readStringUntil('\n');
      for(int i=0; i<64; i++) {
        delete anim[i];
      }
    }
  }
  f.close();

  /*Serial.println(frameNumber);
  for(int frame=0; frame<frameNumber; frame++) {
    //Serial.print("Sending Frame: "); Serial.println(frame);
    for(int i=0; i<strip.PixelCount()/2; i++) {
      strip.SetPixelColor( i     , *anim[frame][i]);
      strip.SetPixelColor( 64+i  , *anim[frame][i]);
    }
    strip.Show();
    delay(framespeed);
  }*/

  /*for(int frame=0; frame<frameNumber; frame++) {
    for(int j=0; j<8; j++) {
      for(int i=0; i<8; i++) {
        delete anim[frame][i*8+j];
        }
      }
    }*/  
}
