// estefania
#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <random>
void print_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
void fill_matrix_hilbert(std::vector<double> & M, const int nrows, const int ncols);
void fill_matrix_identity(std::vector<double> & M, const int nrows, const int ncols);
bool check_idempotent(const std::vector<double> & M, int n, int power, double eps);
void compute_power(const std::vector<double> & M, int n, int power, 
                    std::vector<double> & B);
void matmul(const std::vector<double> & A, int nrows, int ncols, 
            const std::vector<double> & B, 
            std::vector<double> & C);
