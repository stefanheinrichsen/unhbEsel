int getFileFrames(char* file) {
  File f = SPIFFS.open(file, "r");
  String line;
  int n = -1;
  int result;
  
  if (!f) {
    Serial.println("Cannot open file!");
    return -1;
  } else {
      
      while(f.available() && n<0) {
        line = f.readStringUntil('\n');
        n = line.lastIndexOf("FRAME_COUNT");
      }
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
      
      if(frame<frameNumber-1) line = f.readStringUntil('\n'); line = f.readStringUntil('\n');
      for(int i=0; i<64; i++) {
        delete anim[i];
      }
    }
  }
  f.close();
}

void playLRFile(char* lfile, char* rfile, int framespeed) {
  int leftFrameNumber  = getFileFrames(lfile);
  int rightFrameNumber = getFileFrames(rfile);
  int n = -1;
  RgbColor *lanim[64];
  RgbColor *ranim[64];;

  File lf = SPIFFS.open(lfile, "r");
  File rf = SPIFFS.open(rfile, "r");
  
  String lline, rline;
  char rgbChar[8];
  String rgbStr;
  uint32_t rgb;

  if(leftFrameNumber != rightFrameNumber) { Serial.println("Frame mismatch for playLRFile"); return; }
  
  // load file into array
  if (!lf | !rf) {
    Serial.println("Cannot open any of the left-/rightfile!");
    return;
  } else {
      // forward to first hex number
      while(lf.available() && n<0) {
        lline = lf.readStringUntil('\n');
        n = lline.lastIndexOf("0x");
      }
      n=-1;
      while(rf.available() && n<0) {
        rline = rf.readStringUntil('\n');
        n = rline.lastIndexOf("0x");
      }
      
      for(int frame=0; frame<leftFrameNumber; frame++) {
        for(int j=0; j<8; j++) {
          for(int i=0; i<8; i++) {
            rgbStr=lline.substring(4+i*12,4+i*12+6);
            rgb = strtol(rgbStr.c_str(), NULL, 16);
            lanim[i*8+j] = new RgbColor(rgb & 0xFF, rgb>>8 & 0xFF, rgb>>16);
            strip.SetPixelColor( i*8+j     , *lanim[i*8+j]);

            rgbStr=rline.substring(4+i*12,4+i*12+6);
            rgb = strtol(rgbStr.c_str(), NULL, 16);
            ranim[i*8+j] = new RgbColor(rgb & 0xFF, rgb>>8 & 0xFF, rgb>>16);
            strip.SetPixelColor( 64+i*8+j     , *ranim[i*8+j]);
          }
        lline = lf.readStringUntil('\n');
        rline = rf.readStringUntil('\n');
      }
      strip.Show();
      delay(framespeed);
      
      if(frame<leftFrameNumber-1) { 
        lline = lf.readStringUntil('\n'); lline = lf.readStringUntil('\n');
        rline = rf.readStringUntil('\n'); rline = rf.readStringUntil('\n');
      }
      for(int i=0; i<64; i++) {
        delete lanim[i];
        delete ranim[i];
      }
    }
  }
  lf.close();
  rf.close(); 
}

void playWideFile(char* file, int framespeed) {
  int frameNumber = getFileFrames(file);
  int n = -1;
  RgbColor *anim[128];;

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
          for(int i=0; i<16; i++) {
            String rgbStr=line.substring(4+i*12,4+i*12+6);
            uint32_t rgb = strtol(rgbStr.c_str(), NULL, 16);
            anim[i*8+j] = new RgbColor(rgb & 0xFF, rgb>>8 & 0xFF, rgb>>16);
            strip.SetPixelColor( i*8+j     , *anim[i*8+j]);
          }
        line = f.readStringUntil('\n');
      }
      strip.Show();
      delay(framespeed);
      
      if(frame<frameNumber-1) line = f.readStringUntil('\n'); line = f.readStringUntil('\n');
      for(int i=0; i<128; i++) {
        delete anim[i];
      }
    }
  }
  f.close();
}
