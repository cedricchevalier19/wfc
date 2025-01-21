// Grid data structure

#pragma once

#include <memory>

template <typename ScalarType>
class Grid;

template <int N, typename ScalarType>
class TileView {
public:
    // Define a Tile from the grid
    TileView(const Grid<ScalarType>* grid, size_t offset): m_grid(grid), m_offset(offset) {
    }

private:
    const Grid<ScalarType>* m_grid;
    size_t m_offset;
};

template <typename ScalarType>
class Grid
{
public:
    Grid(int rows, int cols)
    :m_rows(rows), m_cols(cols) {
        m_data = std::make_unique<ScalarType>(m_rows*m_cols);
    }

    ScalarType& operator()(int row, int col) {
        return m_data[offset(row, col)];
    }

    const ScalarType& operator()(int row, int col) const {
        return m_data[offset(row, col)];
    }

    template<int N>
    TileView<N, ScalarType> tile(int row, int col) const {
        return {this, offset(row, col)};
    }

private:
    auto offset(int row, int col) const {
        return row*m_cols + col;
    }

    int m_rows = 0;
    int m_cols = 0;
    std::unique_ptr<ScalarType> m_data;
};
