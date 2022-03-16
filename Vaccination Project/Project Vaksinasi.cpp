#include<stdio.h>

//Judul Program
void headline(){
    printf("\t\t\t\t\t   VAKSINASI NEGARA ATLANTIS\n");
    printf("\t\t\t\t=============================================\n");
    printf("\t\t\t\tMade by: Pristian Budi Dharmawan - 2501983105\n");
    printf("\t\t\t\t\t\t\t\t   Ver 2.8.15\n"); //Last Updated on 21/11/2021 1.48
}

//Mengisi data vaksin dan validasi apakah vaksin ini masih ada atau tidak
char namaVks[1000], batchVks[1000], kadalVks[1000], statVks;
void dataVaksin(){
    printf("\nData Vaksin:\n");
    printf("\ta. Nama Vaksin: ");
    scanf("%[^\n]", &namaVks); getchar(); 
    //Daripada menggunakan \n di dalam scanf akan jauh lebih efektif jika menggunakan getchar dan tidak perlu menekan tombol CTRL+Z 
    printf("\tb. Batch Vaksin: ");
    scanf("%s", &batchVks); getchar();
    while(statVks != 'Y' && statVks != 'y' && statVks != 'N' && statVks != 'n'){
        printf("\tc. Apakah vaksin ini pernah digunakan atau belum / Stock vaksin sudah habis?(Y/N) ");
        scanf("%c", &statVks); getchar();
    } if(statVks == 'Y' || statVks == 'y'){
        printf("\n\t\t\t---Silahkan input kembali vaksin yang belum digunakan (out of stock)---");
    } else if(statVks == 'N' || statVks == 'n'){
        printf("\td. Masukkan kadaluarsa vaksin(DD/MM/YYYY): ");
        scanf("%s", &kadalVks); getchar();
        printf("\n\t\t     ---Selamat vaksin ini dapat digunakan sebelum tanggal %s!---\n", kadalVks);
    }
}

//Mengisi data peserta
char nama[1000], nik[1000], ttl[1000], alamat[1000], noHp[1000], alamatTamb, alamatTamb1[1000];
void dataPeserta(){
    printf("\nSilahkan isi data peserta vaksin Di bawah ini:\n"); 
    printf("\t1. NIK: "); 
    scanf("%[^\n]", &nik); getchar();
    printf("\t2. Nama: "); 
    scanf("%[^\n]", &nama); getchar();
    printf("\t3. Tempat/Tanggal Lahir: ");
    scanf("%[^\n]", &ttl); getchar();
    while(alamatTamb != 'Y' && alamatTamb != 'y' && alamatTamb != 'N' && alamatTamb != 'n'){
        printf("\tApakah anda memiliki alamat tambahan?(Y/N) ");
        scanf("%c", &alamatTamb); getchar();
    } if(alamatTamb == 'Y' || alamatTamb == 'y'){
        printf("\t4a. Alamat: ");
        scanf("%[^\n]", &alamat); getchar(); 
        printf("\t4b. Alamat Lain: ");
        scanf("%[^\n]", &alamatTamb1); getchar();
        printf("\t5. No HP: ");
        scanf("%[^\n]", &noHp); getchar(); 
        printf("\nProccessing data.....\n");
    } else if(alamatTamb == 'N' || alamatTamb == 'n'){
        printf("\t4. Alamat: ");
        scanf("%[^\n]", &alamat); getchar(); 
        printf("\t5. No HP: ");
        scanf("%[^\n]", &noHp); getchar(); 
        printf("\nProccessing data.....\n");
    }
}

//Mengisi data nakes
char namaNakes[1000], nomorPraktek, lokasiVaksin[1000];
void dataNakes(){
    printf("\nSilahkan input data NAKES yang bertugas dibawah ini:\n");
    printf("\t1. Nama NAKES: ");
    scanf("%[^\n]", &namaNakes); getchar();
    printf("\t2. Nomor Praktek: ");
    scanf("%s", &nomorPraktek); getchar();
    printf("\t3. Lokasi Vaksin: ");
    scanf("%[^\n]", &lokasiVaksin); getchar();
    printf("\nPasien a/n %s akan ditangani oleh NAKES %s silahkan menunggu di tempat tunggu\n", nama, namaNakes); 
    
}

//Validasi sudah vaksin atau belum serta tindakan vaksinasi
char sdhVaksin, vaksinKe, dipanggil; int tglVaksin1, blnVaksin1, thnVaksin1, tglVaksin2, blnVaksin2, thnVaksin2;
void vaksinBelum(){
    printf("------------------------------------------------------------------------------\n");
    printf("Memanggil pasien.....\n");
    while(sdhVaksin != 'Y' && sdhVaksin != 'y' && sdhVaksin != 'N' && sdhVaksin != 'n'){
        printf("\nApakah Pasien sudah vaksin sebelumnya?(Y/N) "); 
        //Jika sudah maka akan melakukan vaksinasi kedua
        //Jika belum maka akan melakukan vaksinasi pertama
        scanf("%c", &sdhVaksin); getchar();
    } if(sdhVaksin == 'N' || sdhVaksin == 'n'){ 
        while(vaksinKe != 'Y' && vaksinKe != 'y'){
            printf("Ingin vaksinasi sekarang?(Y/N) ");
            scanf("%c", &vaksinKe); getchar();  
            //Asumsi jika pasien tidak ingin vaksinasi sekarang maka akan looping sampai siap vaksin
            if(vaksinKe == 'N' || vaksinKe == 'n'){
                printf("\nTekan Y jika sudah siap\n\n");
            }
        } if(vaksinKe == 'Y'){
            printf("Tanggal vaksin ke-1/Hari ini (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &tglVaksin1, &blnVaksin1, &thnVaksin1); getchar();
            printf("\n\nPasien akan melakukan vaksinasi tahap ke-1\n");
            printf("Pasien sedang divaksinasi tahap ke-1, harap tunggu...\n");
            printf("\n\t\t---%s dengan NIK %s telah melakukan vaksin ke-1 dengan vaksin %s!!!---\n\n\n\n", nama, nik, namaVks);
            printf("Press ENTER to generate your second vaccine schedule...."); getchar();
        }
    } else if(sdhVaksin == 'Y' || sdhVaksin == 'y'){    
        while(vaksinKe != '1'){
            printf("Vaksinasi ke-berapa: ");
            scanf("%c", &vaksinKe); getchar();
            if(vaksinKe != '1'){
                printf("\nData Tidak Valid\nVaksinasi masih sampai dengan dosis pertama\n");
                printf("Silahkan input kembali\n\n");
            }  
        } if(vaksinKe == '1'){
            printf("Tanggal vaksin ke-1 (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &tglVaksin1, &blnVaksin1, &thnVaksin1); getchar();
            printf("Tanggal vaksin ke-2/Hari ini (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &tglVaksin2, &blnVaksin2, &thnVaksin2); getchar();
            printf("\n\nPasien akan melakukan vaksinasi tahap ke-2\n");
            printf("Pasien sedang divaksinasi tahap ke-2, harap tunggu...\n");
            printf("\n\t\t---%s dengan NIK %s telah melakukan vaksin ke-2 dengan vaksin %s!!!---\n\n\n\n", nama, nik, namaVks);
            printf("Press ENTER to generate your third vaccine schedule...."); getchar();
        }
    }
}

//Menghitung Jadwal vaksinasi berikutnya
void dateCalculator(){
    printf("\n\n\n\n\n\n***************************************\n");
    printf("Jadwal vaksinasi berikutnya:\n");
    printf("Tempat Vaksinasi: %s\n", lokasiVaksin);
    int thVks1 = thnVaksin1, thVks2 = thnVaksin2, blVks1 = blnVaksin1, blVks2 = blnVaksin2; 
    //Sebagai counter agar di fungsi setelahnya tdk print value yg sama dari tanggal
    if(vaksinKe == 'Y'){
        blVks1 += 1;
        if(blVks1 == 13){
             blVks1 = 1;
             thVks1 += 1;
        }
        printf("Tanggal Vaksinasi Kedua: ");
        if(tglVaksin1 < 10){
            printf("0%d/", tglVaksin1);
        } else{
            printf("%d/", tglVaksin1);
        } if(blVks1 < 10){
            printf("0%d/", blVks1);
        } else{
            printf("%d/", blVks1);
        } 
        printf("%d\n", thVks1);
        printf("\nPastikan anda tidak datang terlambat!\n");
    } else if(vaksinKe == '1'){
        thVks2 += 1;
        if(blVks2 == 13){
            blVks2 == 1;
        }
        printf("Tanggal Vaksinasi Ketiga: ");
        if(tglVaksin2 < 10){
            printf("0%d/", tglVaksin2);
        } else{
            printf("%d/", tglVaksin2);
        } if(blVks2 < 10){
            printf("0%d/", blVks2);
        } else{
            printf("%d/", blVks2);
        } 
        printf("%d\n", thVks2);
        printf("\nPastikan anda tidak datang terlambat!\n");
    }
    printf("\n***************************************\n");
}

//Generate Sertifikat Vaksin
void generator(){
    printf("\n\n\n\n\n\n============================================================\n");
    printf("Terima Kasih sudah melakukan vaksinasi hari ini :D\n");
    if(vaksinKe == 'Y'){
        printf("============================================================\n");
        printf("-----------------FIRST VACCINE CERTIFICATE------------------\n\n");
        printf("Diberikan Kepada: \n");
        printf("\t\t%s\n", nama);
        printf("____________________________________________________________\n");
        printf("NIK: %s", nik);
        printf("\t         Tanggal Lahir: %s\n", ttl);
        printf("\n\nTelah Vaksin dosis SATU di %s pada tanggal ", lokasiVaksin);
        if(blnVaksin1 == 13) blnVaksin1 = 1;
        if(tglVaksin1 < 10){
            printf("0%d/", tglVaksin1);
        } else{
            printf("%d/", tglVaksin1);
        } if(blnVaksin1 < 10){
            printf("0%d/", blnVaksin1);
        } else{
            printf("%d/", blnVaksin1);
        } 
        printf("%d\n\n", thnVaksin1);
        printf("------------------------------------------------------------\n");
        printf("NOMOR SERTIFIKAT ANDA\n");
        printf("VKS1-");
        if(blnVaksin1 == 13) blnVaksin1 = 1;
        printf("%d", thnVaksin1);
        if(blnVaksin1 < 10){
            printf("0%d", blnVaksin1);
        } else{
            printf("%d", blnVaksin1);
        } if(tglVaksin1 < 10){
            printf("0%d", tglVaksin1);
        } else{
            printf("%d", tglVaksin1);
        } 
        printf("-%s\n", nik);
        printf("\nDengan Batch Vaksin: %s\n", batchVks);
        printf("Divaksin oleh: %s\n", namaNakes);
        printf("Jenis Vaksin: %s\n", namaVks);
        printf("Sesuai dengan Peraturan Menteri Kesehatan Republik Atlantis\n");
    } else if(vaksinKe == '1'){
        printf("============================================================\n\n");
        printf("-----------------SECOND VACCINE CERTIFICATE-----------------\n\n");
        printf("Diberikan Kepada: \n");
        printf("\t\t%s\n", nama);
        printf("____________________________________________________________\n");
        printf("NIK: %s", nik);
        printf("\t         Tanggal Lahir: %s\n", ttl);
        printf("\n\nTelah Vaksin dosis DUA di %s pada tanggal ", lokasiVaksin);
        if(blnVaksin2 == 13) blnVaksin2 = 1;
        if(tglVaksin2 < 10){
            printf("0%d/", tglVaksin2);
        } else{
            printf("%d/", tglVaksin2);
        } if(blnVaksin2 < 10){
            printf("0%d/", blnVaksin2);
        } else{
            printf("%d/", blnVaksin2);
        } 
        printf("%d\n\n", thnVaksin2);
        printf("------------------------------------------------------------\n");
        printf("NOMOR SERTIFIKAT ANDA\n");
        printf("VKS2-");
        if(blnVaksin2 == 13) blnVaksin2 = 1;
        printf("%d", thnVaksin2);
        if(blnVaksin2 < 10){
        printf("0%d", blnVaksin2);
        } else{
            printf("%d", blnVaksin2);
        } if(tglVaksin2 < 10){
            printf("0%d", tglVaksin2);
        } else{
            printf("%d", tglVaksin2);
        } 
        printf("-%s\n", nik);
        printf("\nDengan Batch Vaksin: %s\n", batchVks);
        printf("Divaksin oleh: %s\n", namaNakes);
        printf("Jenis Vaksin: %s\n", namaVks);
        printf("Sesuai dengan Peraturan Menteri Kesehatan Republik Atlantis\n");
    }
}

int main(){
    headline();
    printf("\n\nSilahkan Input Data Vaksin, Peserta Vaksin, dan Nakes dibawah ini:\n");
    printf("------------------------------------------------------------------\n");
    dataVaksin();
    if(statVks == 'N' || statVks == 'n'){
        dataPeserta();
        dataNakes();
        vaksinBelum();
        dateCalculator();
        printf("\n\n\n\n\n\nPress ENTER to generate your Vaccine Sertificate...."); getchar();
        generator();
        printf("============================================================\n");
    } return 0;
}

