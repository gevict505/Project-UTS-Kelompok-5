#include <stdio.h>
#include <string.h>

int main() {
    int jumlah_mahasiswa = 1; // Dibatasi 2 mahasiswa untuk contoh pengujian
    
    // Array untuk menampung data mahasiswa
    char nama[2][50];
    char nrp[2][20];
    int semester[2];
    float ipk[2];
    long penghasilan[2]; // Berfungsi sebagai "data pendukung yang diperlukan"
    
    // Array untuk menampung hasil seleksi
    int status[2]; // 1 = Memenuhi (Lulus), 0 = Tidak Memenuhi (Gagal)
    char alasan[2][100];

    printf("=== PROGRAM SISTEM SELEKSI BEASISWA ===\n\n");

    // ==========================================
    // BAGIAN MAHASISWA 1: Data Mahasiswa & Input
    // ==========================================
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("--- Input Data Mahasiswa ke-%d ---\n", i + 1);
        
        printf("Masukkan Nama: ");
        scanf(" %[^\n]s", nama[i]);
        
        printf("Masukkan NRP: ");
        scanf("%s", nrp[i]);
        
        // Validasi Semester menggunakan do-while (Minimal semester 1)
        do {
            printf("Masukkan Semester (Minimal 1): ");
            scanf("%d", &semester[i]);
            if (semester[i] < 1) {
                printf("Error: Semester tidak valid. Harus >= 1.\n");
            }
        } while (semester[i] < 1);

        // Validasi IPK menggunakan do-while (0.00 - 4.00)
        do {
            printf("Masukkan IPK (0.00 - 4.00): ");
            scanf("%f", &ipk[i]);
            if (ipk[i] < 0.0 || ipk[i] > 4.0) {
                printf("Error: IPK tidak valid. Harus antara 0.00 dan 4.00.\n");
            }
        } while (ipk[i] < 0.0 || ipk[i] > 4.0);

        // Input data pendukung
        printf("Masukkan Penghasilan Orang Tua (Rp): ");
        scanf("%ld", &penghasilan[i]);
        printf("\n");
    }

    // ==========================================
    // BAGIAN MAHASISWA 2: Proses Seleksi
    // ==========================================
    // Kriteria: IPK >= 3.0, Semester >= 3, Penghasilan <= 5.000.000
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (ipk[i] >= 3.0 && semester[i] >= 3 && penghasilan[i] <= 5000000) {
            status[i] = 1; // Memenuhi kriteria
            strcpy(alasan[i], "Memenuhi semua kriteria.");
        } else {
            status[i] = 0; // Tidak memenuhi kriteria
            
            // Menentukan alasan tidak lulus dengan if-else
            if (ipk[i] < 3.0) {
                strcpy(alasan[i], "IPK kurang dari kriteria minimum (3.00).");
            } else if (semester[i] < 3) {
                strcpy(alasan[i], "Semester belum mencukupi (minimal semester 3).");
            } else {
                strcpy(alasan[i], "Penghasilan orang tua melebihi batas (Rp 5.000.000).");
            }
        }
    }

    // ==========================================
    // BAGIAN MAHASISWA 3: Hasil & Pengujian
    // ==========================================
    int rekap_lulus = 0;
    int rekap_gagal = 0;

    printf("=== HASIL SELEKSI BEASISWA ===\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("\nNama  : %s\n", nama[i]);
        printf("NRP   : %s\n", nrp[i]);
        
        // Menampilkan hasil dan alasan
        if (status[i] == 1) {
            printf("Status: MEMENUHI SYARAT\n");
            rekap_lulus++;
        } else {
            printf("Status: TIDAK MEMENUHI SYARAT\n");
            rekap_gagal++;
        }
        printf("Alasan: %s\n", alasan[i]);
    }

    // Menampilkan Rekap Hasil
    printf("\n=== REKAPITULASI HASIL ===\n");
    printf("Total Mahasiswa Diuji : %d\n", jumlah_mahasiswa);
    printf("Total Memenuhi        : %d\n", rekap_lulus);
    printf("Total Tidak Memenuhi  : %d\n", rekap_gagal);

    return 0;
}