#include <bits/stdc++.h>
#include <omp.h>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 0;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
    {
        int num = rand()%n;
        numbers[i]=num;
    }

    // Serial Operations
    int min_val_serial = numbers[0];
    int max_val_serial = numbers[0];
    double sum_serial = 0;

    auto start_serial = high_resolution_clock::now();

    for (int i = 0; i < numbers.size(); i++) {
        min_val_serial = min(min_val_serial, numbers[i]);
        max_val_serial = max(max_val_serial, numbers[i]);
        sum_serial += numbers[i];
    }

    double average_serial = sum_serial / numbers.size();

    auto end_serial = high_resolution_clock::now();
    auto duration_serial = duration_cast<microseconds>(end_serial - start_serial);

    cout << "Serial Results:" << endl;
    cout << "Minimum value: " << min_val_serial << endl;
    cout << "Maximum value: " << max_val_serial << endl;
    cout << "Sum: " << sum_serial << endl;
    cout << "Average: " << average_serial << endl;
    cout << "Serial Execution Time: " << duration_serial.count() << " microseconds" << endl;

    // Parallel Operations
    int min_val_parallel = numbers[0];
    int max_val_parallel = numbers[0];
    double sum_parallel = 0;

    auto start_parallel = high_resolution_clock::now();

    #pragma omp parallel for reduction(min:min_val_parallel) reduction(max:max_val_parallel) reduction(+:sum_parallel)
    for (int i = 0; i < numbers.size(); i++) {
        min_val_parallel = min(min_val_parallel, numbers[i]);
        max_val_parallel = max(max_val_parallel, numbers[i]);
        sum_parallel += numbers[i];
    }

    double average_parallel = sum_parallel / numbers.size();

    auto end_parallel = high_resolution_clock::now();
    auto duration_parallel = duration_cast<microseconds>(end_parallel - start_parallel);

    cout << "\nParallel Results:" << endl;
    cout << "Minimum value: " << min_val_parallel << endl;
    cout << "Maximum value: " << max_val_parallel << endl;
    cout << "Sum: " << sum_parallel << endl;
    cout << "Average: " << average_parallel << endl;
    cout << "Parallel Execution Time: " << duration_parallel.count() << " microseconds" << endl;

    return 0;
}
