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

#include "SoundTouch.h"

SoundTouch::SoundTouch()
{
    handle = soundtouch_createInstance();
}

SoundTouch::~SoundTouch()
{
    soundtouch_destroyInstance(handle);
}

const char *SoundTouch::getVersionString() {
    return soundtouch_getVersionString();
}

void SoundTouch::getVersionString2(char* versionString, int bufferSize) {
    soundtouch_getVersionString2(versionString, bufferSize);
}

unsigned int SoundTouch::getVersionId() {
    return soundtouch_getVersionId();
}

void SoundTouch::setRate(float newRate) {
    soundtouch_setRate(handle, newRate);
}

void SoundTouch::setTempo(float newTempo) {
    soundtouch_setTempo(handle, newTempo);
}

void SoundTouch::setRateChange(float newRate) {
    soundtouch_setRateChange(handle, newRate);
}

void SoundTouch::setTempoChange(float newTempo) {
    soundtouch_setTempoChange(handle, newTempo);
}

void SoundTouch::setPitch(float newPitch) {
    soundtouch_setPitch(handle, newPitch);
}

void SoundTouch::setPitchOctaves(float newPitch) {
    soundtouch_setPitchOctaves(handle, newPitch);
}

void SoundTouch::setPitchSemiTones(float newPitch) {
    soundtouch_setPitchSemiTones(handle, newPitch);
}

void SoundTouch::setChannels(unsigned int numChannels) {
    soundtouch_setChannels(handle, numChannels);
}

void SoundTouch::setSampleRate(unsigned int srate) {
    soundtouch_setSampleRate(handle, srate);
}

void SoundTouch::flush() {
    soundtouch_flush(handle);
}

void SoundTouch::putSamples(const float *samples, unsigned int numSamples) {
    soundtouch_putSamples(handle, samples, numSamples);
}

void SoundTouch::clear() {
    soundtouch_clear(handle);
}

bool SoundTouch::setSetting(int settingId, int value) {
    return soundtouch_setSetting(handle, settingId, value);
}

int SoundTouch::getSetting(int settingId) {
    return soundtouch_getSetting(handle, settingId);
}

int SoundTouch::receiveSamples(float *outBuffer, unsigned int maxSamples) {
    return soundtouch_receiveSamples(handle, outBuffer, maxSamples);
}

int SoundTouch::numSamples() {
    return soundtouch_numSamples(handle);
}

int SoundTouch::numUnprocessedSamples() {
    return soundtouch_numUnprocessedSamples(handle);
}

int SoundTouch::isEmpty() {
    return soundtouch_isEmpty(handle);
}
