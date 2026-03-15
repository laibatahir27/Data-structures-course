#include<iostream>
#include<chrono>   // used chrono library for calculating execeution time.
#include<fstream>

const int size = 5;
                                  // Functions declaration
void wrong_selection(int *arr, int size);
void corr_selection(int *arr, int size);
void insertion(int *arr, int size);
void bubble(int *arr, int size);
void display(int*arr, int size);
void write_csv(int avg1, int avg2, int avg3, int avg4, int avg5, int
	avg6, int avg7, int avg8, int avg9, int avg10, int avg11, int avg12,int size);

int main() {

	srand(time(NULL));
	int A[size];
	int B[size] = { 2,7,44,67,70 };   // ascending order array
	int C[size] = { 99,50,42,8,3 };   // descending order array
	int sum1 = 0,sum2 = 0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0,sum10=0,sum11=0,sum12=0;

		                                 // Random array

	    std::cout << "\t\t\t\t" << "For Array A:";

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < size; j++) {
				A[j] = rand();
				std::cout << A[j] << " ";
			}

			std::cout << std::endl;

			auto t1 = std::chrono::high_resolution_clock::now();
			wrong_selection(A, size);   // Calling wrong_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum1 += duration1;
			std::cout << "Duration:" << duration1 << std::endl;
			display(A, size);
		}
		int avg1 = sum1 / 10;


		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < size; j++) {
				A[j] = rand();
				std::cout << A[j] << " ";
			}

			std::cout << std::endl;

			auto t1 = std::chrono::high_resolution_clock::now();
			corr_selection(A, size);   // Calling corr_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum2 += duration2;
			std::cout << "Duration:" << duration2 << std::endl;
			display(A, size);
		}
		int avg2 = sum2 / 10;


		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < size; j++) {
				A[j] = rand();
				std::cout << A[j] << " ";
			}

			std::cout << std::endl;

			auto t1 = std::chrono::high_resolution_clock::now();
			insertion(A, size);    // Calling insertion() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum3 += duration3;
			std::cout << "Duration:" << duration3 << std::endl;
			display(A, size);
		}
		int avg3 = sum3 / 10;


		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < size; j++) {
				A[j] = rand();
				std::cout << A[j] << " ";
			}

			std::cout << std::endl;

			auto t1 = std::chrono::high_resolution_clock::now();
			bubble(A, size);    // Calling bubble() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum4 += duration4;
			std::cout << "Duration:" << duration4 << std::endl;
			display(A, size);
		}
		int avg4 = sum4 / 10;

		                                   // Ascending order array

		std::cout << "\t\t\t\t" << " For array B:2,5,7,9,11 " << std::endl;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			wrong_selection(B, size);     // Calling wrong_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum5 += duration5;
			std::cout << "Duration:" << duration5 << std::endl;
			display(B, size);
		}
		int avg5 = sum5 / 10;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			corr_selection(B, size);     // Calling corr_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum6 += duration6;
			std::cout << "Duration:" << duration6 << std::endl;
			display(B, size);
		}
		int avg6 = sum6 / 10;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			insertion(B, size);     // Calling insertion() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration7 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum7 += duration7;
			std::cout << "Duration:" << duration7 << std::endl;
			display(B, size);
		}
		int avg7 = sum7 / 10;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			bubble(B, size);        // Calling bubble() function 
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration8 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum8 += duration8;
			std::cout << "Duration:" << duration8 << std::endl;
			display(B, size);
		}
		int avg8 = sum8 / 10;

		                                  // Descending order array

		std::cout << "\t\t\t\t" << " For array C:99,50,42,8,3 " << std::endl;

		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			wrong_selection(C, size);     // Calling wrong_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration9 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum9 += duration9;
			std::cout << "Duration:" << duration9 << std::endl;
			display(C, size);
		}
		int avg9 = sum9 / 10;


		for (int i = 0; i < 10; i++) {
			auto  t1 = std::chrono::high_resolution_clock::now();
			corr_selection(C, size);     // Calling corr_selection() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration10 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum10 += duration10;
			std::cout << "Duration:" << duration10 << std::endl;
			display(C, size);
		}
		int avg10 = sum10 / 10;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			insertion(C, size);         // Calling insertion() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration11 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum11 += duration11;
			std::cout << "Duration:" << duration11 << std::endl;
			display(C, size);
		}
		int avg11 = sum11 / 10;


		for (int i = 0; i < 10; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			bubble(C, size);       // Calling bubble() function
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration12 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			sum12 += duration12;
			std::cout << "Duration:" << duration12 << std::endl;
			display(C, size);
		}
		int avg12 = sum12 / 10;
	
	write_csv(avg1,avg2,avg3,avg4,avg5,avg6,avg7,avg8,avg9,avg10,avg11,avg12,size);

}


                                        // display function

void display(int*arr, int size) {
	std::cout << "Sorted Array:";

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

                                        // Correct selection sort

void corr_selection(int *arr, int size) {

	std::cout << "\n";
	std::cout << "Correct Selection sort:-" << std::endl;
	for (int i = 0; i< size - 1; i++) {

		int min = arr[i];
		int mindx = i;

		for (int j = i+ 1; j < size; j++) {
			if (min > arr[j]) {
				min = arr[j];
				mindx = j;
			}
		}
		std::swap(arr[i], arr[mindx]);   // (n-1) swaps
	}
}

                                            // Wrong selection sort

void wrong_selection(int *arr, int size) {

	std::cout << "\n";
	std::cout << "Wrong Selection sort:-" << std::endl;
	for (int i = 0; i < size - 1; i++) {
		int min = arr[i];
		int mindx = i;
		for (int j = i + 1; j < size; j++) {
			if (min > arr[j]) {
				min = arr[j];
				mindx = j;
			}
			std::swap(arr[i], arr[mindx]);  // n^2 swaps
		}
	}
}

                                           // Insertion sort

void insertion(int *arr, int size) {

	std::cout << "\n";
	std::cout << "Insertion sort:-" << std::endl;

	for (int i = 1; i < size; i++) {
		int current = arr[i];
		int j = i;

		while (j > 0) {
			if (arr[j - 1] <= current) {
				break;
			}
			else {
				arr[j] = arr[j - 1];
			}
			j--;
		}
		arr[j] = current;
	}
}

                                                // Bubble sort

void bubble(int *arr, int size) {

	std::cout << "\n";
	std::cout << "Bubble sort:-" << std::endl;

	for (int i = 0; i < size - 1; i++) {

		bool flag = true;
		for (int j = 0; j < size - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				flag = false;
				std::swap(arr[j], arr[j + 1]);
			}
		}
		if (flag) {  
			break;
		}
	}
}
                                                  
                                            // Write data in csv file

void write_csv(int avg1, int avg2, int avg3, int avg4, int avg5, int
	avg6, int avg7, int avg8, int avg9, int avg10, int avg11, int avg12,int size) {

	std::ofstream outfile;
	outfile.open("complexity.csv", std::ios::out);

	if (!outfile) {     // check whether the file is opening or not.
		std::cout << "File not opened";
		return;
	}

	outfile << "Algorithm," << "Array size," << "Array Type," << "Average" << "\n";
    
	// Writing data for Array A(Random array )
	outfile << "Wrong Sel," << size << ",A," << avg1 << "\n";
	outfile << "Corr Sel," << size << ",A," << avg2 << "\n";
	outfile << "Insertion," << size << ",A," << avg3 << "\n";
	outfile << "Bubble," << size << ",A," << avg4 << "\n";

	// Writing data for Array B (Ascending order array)
	outfile << "Wrong Sel," << size << ",B," << avg5 << "\n";
	outfile << "Corr Sel," << size << ",B," << avg6 << "\n";
	outfile << "Insertion," << size << ",B," << avg7 << "\n";
	outfile << "Bubble," << size << ",B," << avg8 << "\n";

	// Writing data for Array C  (Descending order array)
	outfile << "Wrong Sel," << size << ",C," << avg9 << "\n";
	outfile << "Corr Sel," << size << ",C," << avg10 << "\n";
	outfile << "Insertion," << size << ",C," << avg11 << "\n";
	outfile << "Bubble," << size << ",C," << avg12 << "\n";

	outfile.close();      // close the csv file after writing data in it.
}