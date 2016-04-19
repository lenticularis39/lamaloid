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

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <SoundTouch.h>

using namespace std;

void crash(string message) {
    cout << message;
    exit(1);
}

int main(const int argc, const char * argv[])
{
    // File reading test
    char filename[PATH_MAX];
    int bytes;
    int sampleRate;

    char *buffer;
    float *samples;
    long fileSize;

    cout << "Enter filename:";
    cin >> filename;
    cout << "Enter bytes (8, 16, 32, 64): ";
    cin >> bytes;
    cout << "Enter bitrate: ";
    cin >> sampleRate;

    ifstream file;
    file.open(filename, ios::in);
    if(file.tellg() == -1) crash("File does not exist.");

    file.seekg(0, ios::end);
    fileSize = file.tellg();
    buffer = new char[file.tellg()];
    file.seekg(0, ios::beg);
    file.read(buffer, fileSize);

    //for(int i = 0; i < fileSize; i++) cout << buffer[i];

    delete[] buffer;
    file.close();
    return 0;
}
