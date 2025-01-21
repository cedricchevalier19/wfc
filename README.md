# Simple Wave Function Collapse

## Data Structures

All data structures are templated on a `ScalarType` that represents the value of one pixel.

### Grid

A `Grid` represents the domain, i.e. the values for each pixel. It is defined as a cartesian domain, `rows` by `cols`.

### Tile

Tiles are square subgrid of size `N` (which is a template parameter). They define a local valid combination of the
values of a pixel.

## Algorithm

### Overview

```
Inputs: a sample grid S, a problem grid G
1. Generate the list L of valid tiles from S
2. For each tile t of L, compute the list valid(t, offset) of tiles that can overlap with a given offset
3. For each pixel of G, compute its entropy, i.e. the number of possible solutions according to the valid rules previously computed
4. Select the pixel of the lowest entropy and choose randomly a valid solution. If none, it's a fail.
5. Update entropy of the neighbors
6. Loop to 4
7. Return the computed configuration
```