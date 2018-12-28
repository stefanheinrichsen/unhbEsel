#include <stdint.h>

#define TERMINATOR_FRAME_COUNT 9
#define TERMINATOR_FRAME_WIDTH 8
#define TERMINATOR_FRAME_HEIGHT 8

/* Piskel data for "Terminator" */

static const uint32_t terminator_data[9][64] = {
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
},
{
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff111199, 0xff0000ff, 0xff0000ff, 0xff111199, 0xff000000, 0xff111199, 
0xff111199, 0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff000000, 0xff000000, 0xff111199, 
0xff000000, 0xff111199, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff111199, 0xff000000, 
0xff000000, 0xff000000, 0xff111199, 0xff111199, 0xff111199, 0xff111199, 0xff000000, 0xff000000
}
};