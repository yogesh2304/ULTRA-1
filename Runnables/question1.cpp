#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
   
    std::srand(std::time(nullptr));

    
    const int num_pairs = 200;

    
    for (int i = 0; i < num_pairs; ++i) {
        
        int source = std::rand() % 139994; 
        int target = std::rand() % 139994;  

       
        double runtime = runDijkstraAlgorithm(source, target);

      
        std::cout << "Source: " << source << ", Target: " << target << std::endl;
        std::cout << "Total runtime in seconds: " << runtime << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
