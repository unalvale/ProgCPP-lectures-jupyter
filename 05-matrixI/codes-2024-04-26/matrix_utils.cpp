// sediazba
#include "matrix_utils.h"

void print_matrix(const std::vector<double> & M, int nrows, int ncols)
{
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < ncols; ++jj) {
            std::cout << M[ii*ncols + jj] << " "; // (ii, jj) = ii*NCOLS + jj
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(-1, 1);
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = dis(gen);
        }
    }
}

void fill_matrix_hilbert(std::vector<double> & M, const int nrows, const int ncols)
{
    // recorrer irows
    //. recorrer icols
    //   llenar como a_{ij} = 1/(i+j+1)
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = 1.0/(ii + jj + 1);
        }
    }
}

void fill_matrix_identity(std::vector<double> & M, const int nrows, const int ncols)
{
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = 0.0;
            if (ii == jj) {
                M[ii*ncols + jj] = 1.0;
            }
        }
    }
}
bool check_idempotent(const std::vector<double> & M, int n, int power, double eps)
{
    // B = A^p =. A*A*A*A*A.....A , p times
    std::vector<double> B(M.size());
    compute_power(M, n, power, B);

    for (int ii = 0; ii < n; ii++){
        for (int jj = 0; jj < n; jj++){
            if (std::fabs(B[ii*n + jj] - M[ii*n + jj]) >= eps){
                return false;
            } 
        }
    }
    return true;
}

void compute_power(const std::vector<double> & M, int n, int power, 
                    std::vector<double> & B)
{
    // B = A*A*A*A...
    // asumir que existe una funcion que hace la multiplicacion de matriz
    // matmul(A, nrows, ncols, B, C)
    std::vector<double> C(M.size());
    B = M;
    for(int step = 1; step < power; step++) {
        matmul(M, n, n, B, C);
        B = C;
    }     
}

void matmul(const std::vector<double> & A, int nrows, int ncols, 
            const std::vector<double> & B, 
            std::vector<double> & C) 
{
    // C_ij = \sum_k A_ik*B_kj
    // A nrows*ncols
    // B ncols*nrows
    // C nrows*nrows
    int ncols_B = nrows;
    int ncols_C = nrows;
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols_B; jj++){
            C[ii*ncols_C + jj] = 0.0;
            for (int kk = 0; kk < ncols_C; kk++){
                C[ii*ncols_C + jj] += A[ii*ncols + kk]*B[kk*ncols_B + jj];
            }
        }
    }
}