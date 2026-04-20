/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 01
 *   Hari dan Tanggal    : Rabu, 15 April 2026
 *   Nama (NIM)          : M Agni Aulia Fadhly Saepudin (13224042)
 *   Nama File           : soal2.c
 *   Deskripsi           : 
 
    [SOAL 1]
    Mencari dan memulihkan elemen array yang hilang, lalu mencari jumlah subarray maksimum
/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*/
#include <stdio.h>
//#include <math.h>

// fungsi floor
int floor2(int a, int kiri, int kanan) {
    if (a<0){
        return ((kiri+kanan)-1)/2;
    } else {
        return (kiri+kanan)/2;
    }
}

// MaxSubarraySum [1]
int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0];
  
    // Outer loop for starting point of subarray
    for (int i = 0; i < size; i++) {
        int currSum = 0;
      
        // Inner loop for ending point of subarray
        for (int j = i; j < size; j++) {
            currSum = currSum + arr[j];
          
            // Update maxSum if currSum is greater than maxSum
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

int main () {
    // DEKLARASI
    int N;      // jumlah elemen
    
    int maxSum;

    // input
    scanf("%d", &N);
    int a[N];   // array elemen
    for (int i=0; i<N; i++) {
        scanf(" %d", &a[i]);
    }

    
    //printf("cek\n");
    //for (int i=0; i<N; i++) {
    //    printf(" %d", a[i]);
    //} 
    //printf("\n");

    // proses
    for (int i=0; i<N; i++) {
        if (a[i]==-1) {
            // inisialisasi kondisi
            int kanan = -1;
            int kiri = -1;
            
            int has_right = 0; // default false
            int has_left = 0;

            if (i>0) {
                kiri = a[i-1];
                has_left = 1; //true
            }            
            for (int j=i+1; j<N; j++) {
                if (a[j] != -1) {
                    kanan = a[j];
                    has_right = 1; //true
                    break;
                }
            }

            if (has_right&&has_left) {
                if ((kiri+kanan) > 0) {
                    a[i] = (kiri + kanan)/2;
                } else {
                    a[i] = (kiri + kanan -1)/2; //konversi ke integer
                }
                
            } else if (has_left) {
                a[i] = kiri;
            } else if (has_right){
                a[i] = kanan;
            }
            else {
                a[i] = 0; // tidak ada tetangga
            }

        }
    }
    /*for (int i=0; i<N; i++) {
        printf("\n%d", a[i]);
        int temp ;
    }*/
    // Mencari nilai maksimum
    /*int tempMax = a[0];
    for (int i=1; i<N ;i++) {
        if (tempMax<0) {
            tempMax = a[i];
        } 
        else {
            tempMax += a[i];
        }
        if (maxSum < tempMax) {
            maxSum = tempMax;
        }
    }*/

    // output
    printf("RECOVERED");
    for(int i=0; i<N; i++) {
        printf(" %d", a[i]);
    } 
    printf("\n");
    int size = sizeof(a) / sizeof(a[0]);
    //printf ("%d\n", sizeof(a));
    //printf ("%d\n", sizeof(a[0]));
    //printf("%d\n", size);
    printf("MAX_SUM %d", maxSubarraySum(a, size));

    return 0;
}
// [1] https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/
