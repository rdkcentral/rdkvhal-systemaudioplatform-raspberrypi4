#include <cmath>
#include "systemaudioplatform.h"

void systemAudioInitialize()
{
    //NA
}

void systemAudioDeinitialize()
{
    //NA
}

void systemAudioChangePrimaryVol(MixGain gain, int volume)
{
    //NA
}

bool systemAudioGeneratePipeline(GstElement *pipeline, GstElement *source,
                                 GstElement *capsfilter, GstElement **audioSink,
                                 GstElement **audioVolume, AudioType type,
                                 PlayMode mode, SourceType sourceType,
                                 bool smartVolumeEnable)
{
    return false;
}

void systemAudioSetThreshold(double thresHold)
{
    //NA
}

void systemAudioSetVolume(GstElement *audioVolume, AudioType audioType, 
                          PlayMode playMode, int thisVol)
{
     //NA
}

//Player set DetectTime
void systemAudioSetDetectTime(int detectTimeMs)
{   
    //NA
}

//Player set HoldTime
void systemAudioSetHoldTime(int holdTimeMs)
{   
    //NA
}
