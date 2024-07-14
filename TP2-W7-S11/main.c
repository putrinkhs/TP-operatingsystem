#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Deklarasi variabel untuk nama file sumber dan tujuan
    char src_file[256], dst_file[256];

    // Minta nama file sumber dan tujuan dari user
    printf("Masukkan nama file sumber: ");
    scanf("%s", src_file);
    printf("Masukkan nama file tujuan: ");
    scanf("%s", dst_file);

    // Cek apakah file tujuan sudah ada
    if (access(dst_file, F_OK) != -1) {
        printf("File %s sudah ada. Proses copy gagal.\n", dst_file);
        return 1;
    }

    // Buka file sumber dalam mode read-only
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Buka file tujuan dalam mode write-only
    int dst_fd = open(dst_file, O_WRONLY | O_CREAT, 0644);
    if (dst_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }

    // Copy file menggunakan read() dan write()
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(src_fd, buffer, 1024)) > 0) {
        write(dst_fd, buffer, bytes_read);
    }

    // Tutup file sumber dan tujuan
    close(src_fd);
    close(dst_fd);

    printf("File %s berhasil di copy ke %s.\n", src_file, dst_file);

    return 0;
}
