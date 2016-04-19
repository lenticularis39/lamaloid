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

#include "Sample.h"

const char* riff_signature = "RIFF";
const char* wav_signature = "WAVE";

Sample::Sample(char *filename)
// Constructor for loading from a WAV File
{
    unsigned char *buffer;
    long fileSize;
    ifstream file;

    // Read raw data from file to memory
    file.open(filename, ios::in);
    if(file.tellg() == -1) crash("File does not exist.");
    file.seekg(0, ios::end);
    fileSize = file.tellg();
    buffer = new unsigned char[file.tellg()];
    file.seekg(0, ios::beg);
    file.read((char *)buffer, fileSize);
    file.close();

    // Check signature
    if(fileSize < 0x56) crash("Not a WAV file (file too small)");
    for(int i = 0; i <= 3; i++) {
        if(buffer[i] != riff_signature[i]) crash("Not a WAV file (missing RIFF signature)");
    }

    for(int i = 0x08; i <= 0x0B; i++) {
        if(buffer[i] != wav_signature[i - 0x08]) crash("Not a WAV file (missing WAVE signature)");
    }

    // Get sample size, sample rate and channel count
    sampleSize = buffer[0x20]; // It's 1 word long, but there won't be more than 255
    sampleRate = buffer[0x18] + (buffer[0x19] * 256); // Big endian
    channels = buffer[0x16]; // Again - it's 1 word long, but only 1 or 2

    // Print them (debug)
    cout << sampleSize << "-bytes, sample rate " << sampleRate << ", " << (int)channels << " channels." << endl;

    // Not implemented yet

    delete[] buffer;
}

Sample::~Sample()
{
    delete[] samples;
}
