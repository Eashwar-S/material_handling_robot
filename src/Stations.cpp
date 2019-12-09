/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file Stations.cpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Stations class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This program implements the methods of the
 * Stations class from Stations.hpp header file
 *
 */
#include "Stations.hpp"

Stations::Stations() {
  /// Initializing positions to the markers
  Position p1(-2, 3);
  Position p2(0, 3);
  Position p3(-6, 2);
  Position p4(-4, -1.5);
  Position p5(2, -1.5);

  stations.push_back(p1);
  stations.push_back(p2);
  stations.push_back(p3);
  stations.push_back(p4);
  stations.push_back(p5);
}


std::vector<Position>&  Stations::getStations() {
  return stations;
}

Stations::~Stations() {}
