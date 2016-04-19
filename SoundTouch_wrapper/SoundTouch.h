/*  Copyright (C) 2016 Tomáš Glozar

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef SOUNDTOUCH_H
#define SOUNDTOUCH_H

#include <SoundTouchDLL.h>

class SoundTouch
{
    public:
        SoundTouch();
        virtual ~SoundTouch();
        const char *getVersionString();
        void getVersionString2(char* versionString, int bufferSize);
        unsigned int getVersionId();
        void setRate(float newRate);
        void setTempo(float newTempo);
        void setRateChange(float newRate);
        void setTempoChange(float newTempo);
        void setPitch(float newPitch);
        void setPitchOctaves(float newPitch);
        void setPitchSemiTones(float newPitch);
        void setChannels(unsigned int numChannels);
        void setSampleRate(unsigned int srate);
        void flush();
        void putSamples(const float *samples, unsigned int numSamples);
        void clear();
        bool setSetting(int settingId, int value);
        int getSetting(int settingId);
        int receiveSamples(float *outBuffer, unsigned int maxSamples);
        int numSamples();
        int numUnprocessedSamples();
        int isEmpty();

    protected:

    private:
        HANDLE handle;
};

#endif // SOUNDTOUCH_H
