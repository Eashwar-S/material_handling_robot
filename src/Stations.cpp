#include "Stations.hpp"

Stations::Stations() {
  Position p1(1, 2);
  Position p2(2, 3);
  Position p3(4, 6);
  Position p4(5, 8);
  Position p5(9, 10);

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
