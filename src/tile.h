// Tile

#ifndef TILE_H
#define TILE_H

#include <array>

// An owning class that represents a square tile of size N x N
template <int N, typename ScalarType>
class Tile
{
Rea    friend auto operator<=>(const Tile&, const Tile&) = default;
private:
    std::array<ScalarType, N * N> m_data;
};

#endif //TILE_H
