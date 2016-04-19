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

#ifndef SAMPLE_H
#define SAMPLE_H

#include <fstream>
#include <iostream>

using namespace std;

void crash(string message);

class Sample
{
    public:
        float *samples;
        unsigned sampleRate;
        int sampleSize;
        char channels;

        Sample(char *filename);
        virtual ~Sample();

    protected:

    private:
};

#endif // WAVLOADER_H
