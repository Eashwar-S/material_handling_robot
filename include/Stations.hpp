#include "Position.hpp"
#include <vector>

class Stations {
  private:
    std::vector<Position> stations;

  public:
    Stations();
    ~Stations();
    std::vector<Position>&  getStations();
};
