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
    *audioSink = gst_element_factory_make("alsasink", NULL);
    *audioVolume = gst_element_factory_make("volume", NULL);

    bool result = true;

    if (type == MP3)
    {
        GstElement *parser = gst_element_factory_make("mpegaudioparse", NULL);
        GstElement *decodebin = gst_element_factory_make("mpg123audiodec", NULL);
        if (!parser || !decodebin || !*audioVolume || !*audioSink) return false;
        gst_bin_add_many(GST_BIN(pipeline), source, parser, decodebin, *audioVolume, *audioSink, NULL);
        result = gst_element_link_many(source, parser, decodebin, *audioVolume, *audioSink, NULL);
    }
    else if (type == PCM)
    {
        if (sourceType == DATA || sourceType == WEBSOCKET)
        {
            if (!*audioVolume || !*audioSink) return false;
            gst_bin_add_many(GST_BIN(pipeline), source, *audioVolume, *audioSink, NULL);
            result = gst_element_link_many(source, *audioVolume, *audioSink, NULL);
        }
        else
        {
            if (!capsfilter || !*audioVolume || !*audioSink) return false;
            gst_bin_add_many(GST_BIN(pipeline), source, capsfilter, *audioVolume, *audioSink, NULL);
            result = gst_element_link_many(source, capsfilter, *audioVolume, *audioSink, NULL);
        }
    }
    else // WAV
    {
        GstElement *wavparser = gst_element_factory_make("wavparse", NULL);
        if (!wavparser || !*audioVolume || !*audioSink) return false;
        gst_bin_add_many(GST_BIN(pipeline), source, wavparser, *audioVolume, *audioSink, NULL);
        result = gst_element_link_many(source, wavparser, *audioVolume, *audioSink, NULL);
    }
 return result;
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
