// Nama : Asyifa amelia Purba Nim: 240121086
#include <iostream>
#include <string>
using namespace std;

// Data mahasiswa
struct Mahasiswa {
    string nama;
    string npm;
    float nilaiMid;
    float nilaiSemester;
    float nilaiAkhir;
    char nilaiHuruf;
};

// Menghitung Nilai Akhir
float hitungNilaiAkhir(float nilaiMid, float nilaiSemester) {
    return (nilaiMid * 0.4) + (nilaiSemester * 0.6);
}

// Menentukan Nilai Huruf berdasarkan Nilai Akhir
char tentukanNilaiHuruf(float nilaiAkhir) {
    if (nilaiAkhir >= 80) {
        return 'A';
    } else if (nilaiAkhir >= 70) {
        return 'B';
    } else if (nilaiAkhir >= 55) {
        return 'C';
    } else if (nilaiAkhir >= 40) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    const int MAX_MAHASISWA = 100;
    Mahasiswa mhs[MAX_MAHASISWA];
    int jumlahMahasiswa;
    
    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa (maksimal 100): ";
    cin >> jumlahMahasiswa;

    // Mengecek jumlah mahasiswa valid
    if (jumlahMahasiswa <= 0 || jumlahMahasiswa > MAX_MAHASISWA) {
        cout << "Jumlah mahasiswa tidak valid." << endl;
        return 1;
    }

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << endl;
        
        cout << "Nama: ";
        cin.ignore();  // Membersihkan buffer
        getline(cin, mhs[i].nama);
        
        cout << "NPM: ";
        cin >> mhs[i].npm;
        
        cout << "Nilai Mid: ";
        cin >> mhs[i].nilaiMid;
        
        cout << "Nilai Semester: ";
        cin >> mhs[i].nilaiSemester;
        
        // Menghitung Nilai Akhir dan Nilai Huruf
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].nilaiMid, mhs[i].nilaiSemester);
        mhs[i].nilaiHuruf = tentukanNilaiHuruf(mhs[i].nilaiAkhir);
    }

    // Menampilkan hasil
    cout << "\n\nData Nilai Ujian Pemrograman C++:\n";
    cout << "=====================================================\n";
    cout << "No | Nama Mahasiswa | NPM       | Nilai Mid | Nilai Semester | Nilai Akhir | Nilai Huruf\n";
    cout << "-----------------------------------------------------\n";
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << i + 1 << "  | " << mhs[i].nama << " | " << mhs[i].npm
             << " | " << mhs[i].nilaiMid << " | " << mhs[i].nilaiSemester
             << " | " << mhs[i].nilaiAkhir << " | " << mhs[i].nilaiHuruf << endl;
    }

    return 0;
}