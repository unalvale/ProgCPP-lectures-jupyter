//Nicoll
#include "matrix_utils.h"

int main(int argc, char **argv) {
    // read size of matrix
    if (argc != 3) {
        std::cerr << "Error. Usage:\n"
                  << argv[0] << " M N \n"
                  << "M : Rows\n"
                  << "N : Columns\n";
        return 1;
    }
    const int M = std::stoi(argv[1]);
    const int N = std::stoi(argv[2]);

    // create matrix A
    std::vector<double> A(M*N);

    // fill matrix randomly
    // fill_matrix_random(A, M, N, 0); // 0 == seed
    //fill_matrix_hilbert(A, M, N);
    
    fill_matrix_identity(A, M, N);
    A[0*M + 0] = 1.23;
    print_matrix(A, M, N);
    int p = 2;
    double eps = 1.0-3;
    std::cout << check_idempotent(A, p, M, eps) << "\n"; 
    
    // print matrix
    //print_matrix(A, M, N);

    return 0;
}