//
// Created by cedric on 16/01/2025.
//

#ifndef TILE_H
#define TILE_H

#include <array>

// An owning class that represents a square tile of size N x N
template <int N, typename ScalarType>
class Tile
{
    explicit Tile(ScalarType initial_value = 0.0)
    {
        m_data.fill(initial_value);
    }

    explicit Tile(std::array<ScalarType, N*N> data)
        : m_data(data)
    {
    }

    void setRow(int row, const std::array<ScalarType, N>& data)
    {
        for (int i = 0; i < N; ++i)
        {
            m_data[row * N + i] = data[i];
        }
    }

    friend auto operator<=>(const Tile&, const Tile&) = default;
private:
    std::array<ScalarType, N * N> m_data;
};

#endif //TILE_H
