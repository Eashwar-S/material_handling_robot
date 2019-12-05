#include "Stations.hpp"

Stations::Stations() {
  Position p1(-2, 3);
  Position p2(0, 3);
  Position p3(1, 2);
  Position p4(2, 1);
  Position p5(2, 3);

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
