#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account{//deklarasi variabel dengan akun
char username[20];
char pass[20];
};
struct data{//deklarasi  variabel data
int keberangkatan;
int tujuan;
char tanggal[20];
int jumlah;
int hargatotal;
int hargasatuan;
int hargakota;
char departure[100];
char arrival[100];
int time;
char waktu[100];
};
int i;

void regis(char username[], char pass[])//prosedur registrasi user
{
    FILE*user;//file registrasi
    struct account sigup;
    printf("masukan username:");gets(sigup.username);
    printf("masukan password:");gets(sigup.pass);
    user = fopen("user.txt","a+");
    fprintf(user,"%s\n",sigup.username);
    fprintf(user,"%s\n",sigup.pass);
    fclose(user);
}
void login(char username[],char pass[])//prosedur login akun user
{
    FILE*user;//file registrasi
    struct account login;
    int n=0;
    user = fopen("user.txt","r");

    while(!feof(user))
    {
    fscanf(user,"%s\n",login.username);
    fscanf(user,"%s\n",login.pass);
    n++;
    }
    if (strcmp(username,login.username)==0 && strcmp(pass,login.pass)==0)
    {
        printf("\n[login succesful!]\n\n");
        system("pause");
        system("cls");
        apk();
    }
    else
    {
        printf("[ussername or password incorrect!]");
    }


    fclose(user);
}

void pesawat()//prosedur data penumpang pesawat
{
    FILE*data;//file data penumpang
    struct data penumpang;

    printf("1.pekanbaru   6.yogyakarta\n2.aceh        7.bandung\n3.palembang   8.jakarta\n4.padang      9.bali\n5.jambi       10.surabaya\n");
    printf("keberangkatan:");scanf("%d",&penumpang.keberangkatan);
    switch(penumpang.keberangkatan)
    {
        case 1  :penumpang.hargakota=90000;strcpy(penumpang.departure,"pekanbaru");break;
        case 2  :penumpang.hargakota=100000;strcpy(penumpang.departure,"aceh");break;
        case 3  :penumpang.hargakota=110000;strcpy(penumpang.departure,"palembang");break;
        case 4  :penumpang.hargakota=120000;strcpy(penumpang.departure,"padang");break;
        case 5  :penumpang.hargakota=130000;strcpy(penumpang.departure,"jambi");break;
        case 6  :penumpang.hargakota=140000;strcpy(penumpang.departure,"yogyakarta");break;
        case 7  :penumpang.hargakota=150000;strcpy(penumpang.departure,"bandung");break;
        case 8  :penumpang.hargakota=160000;strcpy(penumpang.departure,"jakarta");break;
        case 9  :penumpang.hargakota=170000;strcpy(penumpang.departure,"bali");break;
        case 10 :penumpang.hargakota=180000;strcpy(penumpang.departure,"surabaya");break;
    }
    printf("\n=======||||========\n");
    printf("1.pekanbaru   6.yogyakarta\n2.aceh        7.bandung\n3.palembang   8.jakarta\n4.padang      9.bali\n5.jambi       10.surabaya\n");
    printf("tujuan:");scanf("%d",&penumpang.tujuan);
    if(penumpang.keberangkatan!=penumpang.tujuan)
    {
        switch(penumpang.tujuan)
            {
                case 1 :penumpang.hargasatuan=10;strcpy(penumpang.arrival,"pekanbaru");break;
                case 2 :penumpang.hargasatuan=20;strcpy(penumpang.arrival,"aceh");break;
                case 3 :penumpang.hargasatuan=30;strcpy(penumpang.arrival,"palembang");break;
                case 4 :penumpang.hargasatuan=40;strcpy(penumpang.arrival,"padang");break;
                case 5 :penumpang.hargasatuan=50;strcpy(penumpang.arrival,"jambi");break;
                case 6 :penumpang.hargasatuan=60;strcpy(penumpang.arrival,"yogyakarta");break;
                case 7 :penumpang.hargasatuan=70;strcpy(penumpang.arrival,"bandung");break;
                case 8 :penumpang.hargasatuan=80;strcpy(penumpang.arrival,"jakarta");break;
                case 9 :penumpang.hargasatuan=90;strcpy(penumpang.arrival,"bali");break;
                case 10 :penumpang.hargasatuan=100;strcpy(penumpang.arrival,"surabaya");break;
            }
    }
    else
        printf("error 404 salah input!");


    printf("jumlah penumpang:");scanf("%d",&penumpang.jumlah);
    fflush(stdin);
    printf("tanggal keberangkatan:");gets(penumpang.tanggal);
    int jam[5]={12,20,7,15,10};
    system("cls");
    char sorting;
    printf("\n==DAFTAR HARGA==\n");
    for (i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
        printf("\njam %d  ==>Rp.%d",jam[i],penumpang.hargatotal);
    }
    int cari;

    int j;
    int temp;
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }
    printf("\nurutan harga dari yang termurah\n");
    for(i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
         printf("\n%d.jam %d  ==>Rp.%d",i,jam[i],penumpang.hargatotal);
    }
    printf("\n================\n");
  printf("\n\ncari jam keberangkatan:");scanf("%d",&cari);
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }

    int low=1;
    int high=4;
    int idx=0;
    int mid;
    while (low<=high && idx==0)
    {
        mid=(low+high)/2;
        if(jam[mid]==cari)
            idx=mid;
        else if(jam[mid]<cari)
            low=mid+1;
        else
            high=mid-1;
    }
    if(idx!=9)
        printf("\nwaktu ditemukan pada index ke-%d\n",idx);
    else
        printf("\nwaktu tidak ditemukan\n");

    printf("\n===============\n");

    char nama[100][100];
    char nomor[100][100];
    int rekening;
    int uang;
    system("pause");
    system("cls");
    printf("\n==ISI DATA PENUMPANG==\n");
    for(i=1;i<=penumpang.jumlah;i++)
    {
        fflush(stdin);
        printf("\n%d.Nama:",i);gets(nama[i]);
        printf("nomor KTP/Paspor/ID:");gets(nomor[i]);
    }
    system("cls");
    penumpang.hargatotal=penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*cari;
    printf("\n----SELAMAT DATANG DI MENU PEMBAYARAN---\n");
    printf("\ntotal harga yang akan dibayar:Rp.%d",penumpang.hargatotal);
    printf("\n rekening:987654321 atas nama PT.ANGIN\n");
    do{
    printf("\nmasukan jumlah uang Rp.");scanf("%d",&uang);
    printf("\nrekening tujuan:");scanf("%d",&rekening);
    printf("\n=========================================\n");
    if(uang==penumpang.hargatotal && rekening==987654321)
    {
        printf("\n[terimakasih telah melakukan pembayaran]\n");

    }
    else
    {
        printf("[input harga dan rekening salah!]");
    }

    }while(uang!=penumpang.hargatotal && rekening!=987654321);
    printf("\n========================================\n");
        system("pause");
        system("cls");
        printf("\n\n\n---TIKET ONLINE---");
        for(i=1;i<=penumpang.jumlah;i++)
        {
            printf("\n%d.NAMA:%s\n",i,nama[i]);
            printf("NOMOR IDENTITAS:%d",nomor[i]);
            printf("\nKEBERANGKATAN :%s",penumpang.departure);
            printf("\nTUJUAN:%s",penumpang.arrival);
            printf("\nTANGGAL:%s",penumpang.tanggal);
            printf("\nPUKUL:%d",cari);
        }


    //file daftar penerbangan;

    data = fopen("data.txt","a+");
    fprintf(data,"deapeature=%d\n",penumpang.keberangkatan);
    fprintf(data,"arrival=%d\n",penumpang.tujuan);
    fprintf(data,"\njumlah penumpang=%d",penumpang.jumlah);
    fprintf(data,"\nharga yang dikeluarkan=%d",penumpang.hargatotal);
    fprintf(data,"\n###########################");
    fclose(data);

}


void kereta()//prosedur data penumpang kereta
{

    FILE*keretaapi;//file data penumpang
    struct data penumpang;

    printf("1.malang       6.yogyakarta\n2.solo         7.bandung\n3.banten       8.jakarta\n4.garut        9.banyuwangi\n5.bekasi       10.surabaya\n");
    printf("keberangkatan:");scanf("%d",&penumpang.keberangkatan);
    switch(penumpang.keberangkatan)
    {
        case 1  :penumpang.hargakota=900;strcpy(penumpang.departure,"malang");break;
        case 2  :penumpang.hargakota=1000;strcpy(penumpang.departure,"solo");break;
        case 3  :penumpang.hargakota=1100;strcpy(penumpang.departure,"banten");break;
        case 4  :penumpang.hargakota=1200;strcpy(penumpang.departure,"garut");break;
        case 5  :penumpang.hargakota=1300;strcpy(penumpang.departure,"bekasi");break;
        case 6  :penumpang.hargakota=1400;strcpy(penumpang.departure,"yogyakarta");break;
        case 7  :penumpang.hargakota=1500;strcpy(penumpang.departure,"bandung");break;
        case 8  :penumpang.hargakota=1600;strcpy(penumpang.departure,"jakarta");break;
        case 9  :penumpang.hargakota=1700;strcpy(penumpang.departure,"banyuwangi");break;
        case 10 :penumpang.hargakota=1800;strcpy(penumpang.departure,"surabaya");break;
    }
    printf("\n=======||||========\n");
    printf("1.malang       6.yogyakarta\n2.solo         7.bandung\n3.banten       8.jakarta\n4.garut        9.banyuwangi\n5.bekasi       10.surabaya\n");
    printf("tujuan:");scanf("%d",&penumpang.tujuan);
    if(penumpang.keberangkatan!=penumpang.tujuan)
    {
        switch(penumpang.tujuan)
            {
                case 1 :penumpang.hargasatuan=10;strcpy(penumpang.arrival,"malang");break;
                case 2 :penumpang.hargasatuan=20;strcpy(penumpang.arrival,"solo");break;
                case 3 :penumpang.hargasatuan=30;strcpy(penumpang.arrival,"banten");break;
                case 4 :penumpang.hargasatuan=40;strcpy(penumpang.arrival,"garut");break;
                case 5 :penumpang.hargasatuan=50;strcpy(penumpang.arrival,"bekasi");break;
                case 6 :penumpang.hargasatuan=60;strcpy(penumpang.arrival,"yogyakarta");break;
                case 7 :penumpang.hargasatuan=70;strcpy(penumpang.arrival,"bandung");break;
                case 8 :penumpang.hargasatuan=80;strcpy(penumpang.arrival,"jakarta");break;
                case 9 :penumpang.hargasatuan=90;strcpy(penumpang.arrival,"banyuwangi");break;
                case 10 :penumpang.hargasatuan=100;strcpy(penumpang.arrival,"surabaya");break;
            }
    }
    else
        printf("error 404 salah input!");


    printf("jumlah penumpang:");scanf("%d",&penumpang.jumlah);
    fflush(stdin);
    printf("tanggal keberangkatan:");gets(penumpang.tanggal);
    int jam[5]={12,20,7,15,10};
    system("cls");
    char sorting;
    printf("\n==DAFTAR HARGA==\n");
    for (i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
        printf("\njam %d  ==>Rp.%d",jam[i],penumpang.hargatotal);
    }

    int cari;

    int j;
    int temp;
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }
    printf("\nurutan harga dari yang termurah\n");
    for(i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
         printf("\n%d.jam %d  ==>Rp.%d",i,jam[i],penumpang.hargatotal);
    }
    printf("\n================\n");
  printf("\n\ncari jam keberangkatan:");scanf("%d",&cari);
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }

    int low=1;
    int high=4;
    int idx=0;
    int mid;
    while (low<=high && idx==0)
    {
        mid=(low+high)/2;
        if(jam[mid]==cari)
            idx=mid;
        else if(jam[mid]<cari)
            low=mid+1;
        else
            high=mid-1;
    }
    if(idx!=9)
        printf("\nwaktu ditemukan pada index ke-%d\n",idx);
    else
        printf("\nwaktu tidak ditemukan\n");


    char nama[100][100];
    char nomor[100][100];
    int rekening;
    int uang;
    system("pause");
    system("cls");
    printf("\n==ISI DATA PENUMPANG==\n");

    for(i=1;i<=penumpang.jumlah;i++)
    {
        fflush(stdin);
        printf("\n%d.Nama:",i);gets(nama[i]);
        printf("nomor KTP/Paspor/ID:");gets(nomor[i]);
    }
    system("cls");
    penumpang.hargatotal=penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*cari;
     printf("\n----SELAMAT DATANG DI MENU PEMBAYARAN---\n");
    printf("total harga yang akan dibayar:Rp.%d",penumpang.hargatotal);
    printf("\n rekening:987654321 atas nama PT.ANGIN\n\n");
    do{
    printf("\nmasukan jumlah uang Rp.");scanf("%d",&uang);
    printf("\nrekening tujuan:");scanf("%d",&rekening);
    if(uang==penumpang.hargatotal && rekening==987654321)
    {
        printf("\n[terimakasih telah melakukan pembayaran]\n");

    }
    else
    {
        printf("input harga dan rekening salah!");
    }

    }while(uang!=penumpang.hargatotal && rekening!=987654321);
    system("pause");
    system("cls");

        printf("\n\n\n---TIKET ONLINE---");
        for(i=1;i<=penumpang.jumlah;i++)
        {
            printf("\n%d.NAMA:%s\n",i,nama[i]);
            printf("NOMOR IDENTITAS:%d",nomor[i]);
            printf("\nKEBERANGKATAN :%s",penumpang.departure);
            printf("\nTUJUAN:%s",penumpang.arrival);
            printf("\nTANGGAL:%s",penumpang.tanggal);
            printf("\nPUKUL:%d",cari);
        }


    //file daftar penerbangan;

    keretaapi = fopen("keretaapi.txt","a+");
    fprintf(keretaapi,"deapeature=%d\n",penumpang.keberangkatan);
    fprintf(keretaapi,"arrival=%d\n",penumpang.tujuan);
    fprintf(keretaapi,"\njumlah penumpang=%d",penumpang.jumlah);
    fprintf(keretaapi,"\nharga yang dikeluarkan=%d",penumpang.hargatotal);
    fprintf(keretaapi,"\n###########################");
    fclose(keretaapi);

}

void bus()//prosedur data penumpang pesawat
{
    FILE*databus;//file data penumpang
    struct data penumpang;

    printf("1.pekanbaru   6.yogyakarta\n2.aceh        7.bandung\n3.palembang   8.jakarta\n4.padang      9.bali\n5.jambi       10.surabaya\n");
    printf("keberangkatan:");scanf("%d",&penumpang.keberangkatan);
    switch(penumpang.keberangkatan)
    {
        case 1  :penumpang.hargakota=9000;strcpy(penumpang.departure,"pekanbaru");break;
        case 2  :penumpang.hargakota=10000;strcpy(penumpang.departure,"aceh");break;
        case 3  :penumpang.hargakota=11000;strcpy(penumpang.departure,"palembang");break;
        case 4  :penumpang.hargakota=12000;strcpy(penumpang.departure,"padang");break;
        case 5  :penumpang.hargakota=13000;strcpy(penumpang.departure,"jambi");break;
        case 6  :penumpang.hargakota=14000;strcpy(penumpang.departure,"yogyakarta");break;
        case 7  :penumpang.hargakota=15000;strcpy(penumpang.departure,"bandung");break;
        case 8  :penumpang.hargakota=16000;strcpy(penumpang.departure,"jakarta");break;
        case 9  :penumpang.hargakota=17000;strcpy(penumpang.departure,"bali");break;
        case 10 :penumpang.hargakota=18000;strcpy(penumpang.departure,"surabaya");break;
    }
    printf("\n=======||||========\n");
    printf("1.pekanbaru   6.yogyakarta\n2.aceh        7.bandung\n3.palembang   8.jakarta\n4.padang      9.bali\n5.jambi       10.surabaya\n");
    printf("tujuan:");scanf("%d",&penumpang.tujuan);
    if(penumpang.keberangkatan!=penumpang.tujuan)
    {
        switch(penumpang.tujuan)
            {
                case 1 :penumpang.hargasatuan=10;strcpy(penumpang.arrival,"pekanbaru");break;
                case 2 :penumpang.hargasatuan=20;strcpy(penumpang.arrival,"aceh");break;
                case 3 :penumpang.hargasatuan=30;strcpy(penumpang.arrival,"palembang");break;
                case 4 :penumpang.hargasatuan=40;strcpy(penumpang.arrival,"padang");break;
                case 5 :penumpang.hargasatuan=50;strcpy(penumpang.arrival,"jambi");break;
                case 6 :penumpang.hargasatuan=60;strcpy(penumpang.arrival,"yogyakarta");break;
                case 7 :penumpang.hargasatuan=70;strcpy(penumpang.arrival,"bandung");break;
                case 8 :penumpang.hargasatuan=80;strcpy(penumpang.arrival,"jakarta");break;
                case 9 :penumpang.hargasatuan=90;strcpy(penumpang.arrival,"bali");break;
                case 10 :penumpang.hargasatuan=100;strcpy(penumpang.arrival,"surabaya");break;
            }
    }
    else
        printf("error 404 salah input!");


    printf("jumlah penumpang:");scanf("%d",&penumpang.jumlah);
    fflush(stdin);
    printf("tanggal keberangkatan:");gets(penumpang.tanggal);
    int jam[5]={12,20,7,15,10};
    system("cls");
    char sorting;
    printf("\n==DAFTAR HARGA==\n");
    for (i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
        printf("\njam %d  ==>Rp.%d",jam[i],penumpang.hargatotal);
    }
    int cari;

    int j;
    int temp;
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }
    printf("\nurutan harga dari yang termurah\n");
    for(i=0;i<5;i++)
    {
        penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*jam[i];
         printf("\n%d.jam %d  ==>Rp.%d",i,jam[i],penumpang.hargatotal);
    }
    printf("\n==================\n");
  printf("\n\ncari jam keberangkatan:");scanf("%d",&cari);
    for (j=1;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(jam[i]>jam[i+1])
             {
                 temp=jam[i];
                 jam[i]=jam[i+1];
                 jam[i+1]=temp;
             }
        }
    }

    int low=1;
    int high=4;
    int idx=0;
    int mid;
    while (low<=high && idx==0)
    {
        mid=(low+high)/2;
        if(jam[mid]==cari)
            idx=mid;
        else if(jam[mid]<cari)
            low=mid+1;
        else
            high=mid-1;
    }
    printf("\n===============\n");
    if(idx!=9)
        printf("\nwaktu ditemukan pada index ke-%d\n",idx);
    else
        printf("\nwaktu tidak ditemukan\n");
system("pause");
system("cls");
    char nama[100][100];
    char nomor[100][100];
    int rekening;
    int uang;
printf("\n===ISI DATA PENUMPANG===\n");
    for(i=1;i<=penumpang.jumlah;i++)
    {
        fflush(stdin);
        printf("\n%d.Nama:",i);gets(nama[i]);
        printf("nomor KTP/Paspor/ID:");gets(nomor[i]);
    }
    system("cls");
    printf("\n==SELAMAT DATANG DI MENU PEMBAYARAN==\n");
    penumpang.hargatotal=penumpang.hargatotal=penumpang.jumlah*penumpang.hargasatuan*penumpang.hargakota*cari;
    printf("total harga yang akan dibayar:Rp.%d",penumpang.hargatotal);
    printf("\n rekening:987654321 atas nama PT.ANGIN\n\n");
    do{
    printf("\nmasukan jumlah uang Rp.");scanf("%d",&uang);
    printf("\nrekening tujuan:");scanf("%d",&rekening);
    system("pause");
    system("cls");
        if(uang==penumpang.hargatotal && rekening==987654321)
    {
        printf("\n[terimakasih telah melakukan pembayaran]\n");

    }
    else
    {
        printf("input harga dan rekening salah!");
    }
    }while(uang!=penumpang.hargatotal && rekening!=987654321);

system("pause");
system("cls");
        printf("\n\n\n---TIKET ONLINE---");
        for(i=1;i<=penumpang.jumlah;i++)
        {
            printf("\n%d.NAMA:%s\n",i,nama[i]);
            printf("NOMOR IDENTITAS:%d",nomor[i]);
            printf("\nKEBERANGKATAN :%s",penumpang.departure);
            printf("\nTUJUAN:%s",penumpang.arrival);
            printf("\nTANGGAL:%s",penumpang.tanggal);
            printf("\nPUKUL:%d",cari);
        }


    //file daftar penerbangan;

    databus = fopen("databus.txt","");
    fprintf(databus,"deapeature=%d\n",penumpang.keberangkatan);
    fprintf(databus,"arrival=%d\n",penumpang.tujuan);
    fprintf(databus,"\njumlah penumpang=%d",penumpang.jumlah);
    fprintf(databus,"\nharga yang dikeluarkan=%d",penumpang.hargatotal);
    fprintf(databus,"\n###########################");
    fclose(databus);

}

void apk()//prosedur pilihan
{
    int pilih;
    printf("\n----pilih perjalanan----\n");
    printf("1.pesawat\n2.kereta api\n3.bus\n");
    printf("--------------------------\nmasukan pilihan:\n");
    scanf("%d",&pilih);
    system("cls");
    switch(pilih)
    {
        case 1 :printf("--PESAWAT--\n\n");fflush(stdin);pesawat();break;
        case 2 :printf("--kereta api--\n\n");fflush(stdin);kereta();break;
        case 3 :printf("--bus--\nn");fflush(stdin);bus();
    }
}
int main()//fungsi utama
{
    struct account daftar[20];
    struct account log[20];
    int akun[10];
    printf("---program jasa travel---\n");
    printf("login or sigup:");
    gets(akun);
    if (strcmp(akun,"sigup")==0)
    {
    system("cls");
    printf("-----SIGUP-----\n");
    regis(daftar[20].username,daftar[20].pass);
    system("cls");
    printf("-----LOGIN-----\n");
    printf("username :");gets(log[20].username);
    printf("password :");gets(log[20].pass);

    login(log[20].username,log[20].pass);
    }
    else if (strcmp(akun,"login")==0)
    {
       system("cls");
         printf("-----LOGIN-----\n");
    printf("username :");gets(log[20].username);
    printf("password :");gets(log[20].pass);

    login(log[20].username,log[20].pass);

    }
    else
    {
        printf("mohon pilih dengan menginput login atau sigup");
    }


return 0;
}


