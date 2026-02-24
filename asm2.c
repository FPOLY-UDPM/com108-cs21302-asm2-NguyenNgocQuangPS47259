/******************************************************************************
 * Họ và tên: [Nguyễn Ngọc Quang]
 * MSSV:      [PS47259]
 * Lớp:       [CS21321]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


//========= CHỨC NĂNG BONUS 


void pauseScreen() {
    printf("\nNhan Enter de quay lai menu...");
    while(getchar() != '\n'); 
    getchar();
}


//========= CHỨC NĂNG 1 : KIỂM TRA SỐ NGUYÊN TỐ HOẶC SỐ CHÍNH PHƯƠNG


void chucNang1(){
    int a;
    float x=0;
    printf("xin hãy nhập số nguyên cần kiểm tra :");
    scanf("%f",&x);
    if (x==(int)x)
    {
        int nguyenTo=0;
        int chinhPhuong=0;
        if (x==1)
        {
            printf("Đây là số chính phương\n");
        }else if (x<0)
        {
            printf("đây là số âm (không xét)\n");
        }else if (x==0)
        {
            printf("đây là số 0\n");
        }else
        {
        // kiểm tra số nguyên tố
            for (int i = 2; i < x; i++)
            {
                if ((int)x%i==0)
                {
                    nguyenTo++;
                }
                
            }
            // kiểm tra số chính phương
            for (int j = 2; j*j<=x; j++)
            {
                if ((j*j)==x)
                {
                    chinhPhuong++;
                    break;
                }
                }
            if (nguyenTo==0)
            {
                printf("Đây là số nguyên tố\n");
            }else if (chinhPhuong!=0)
            {
                printf("Đây là số chính phương\n");
            }else
            {
                printf("Đây là số nguyên bình thường\n");
            }
        }
    }else
    {
        printf("đây là số thực\n");
    }
}


//======== CHỨC NĂNG 2 : TÌM BỘI CHUNG NHỎ NHẤT, ỨC CHUNG LỚN NHẤT


void chucNang2() {
    int a, b;

    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    if (a == 0 && b == 0) {
        printf("UCLN khong xac dinh\n");
        printf("BCNN khong xac dinh\n");
        return;
    }

    int x = a < 0 ? -a : a;
    int y = b < 0 ? -b : b;

    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }

    int ucln = x;
    int bcnn = (a / ucln) * b;

    if (bcnn < 0) bcnn = -bcnn;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}


//========= CHỨC NĂNG 3 : TÍNH TIỀN GIỜ KARAOKE


void chucNang3(){
    int gioBatDau=0,gioKetThuc=0;
    float gia=0;
    int gioHat=0;
    printf("xin nhập giờ bắt đầu :");
    scanf("%d",&gioBatDau);
    printf("xin nhập giờ kết thúc :");
    scanf("%d",&gioKetThuc);
    do
    {
        printf("giờ hát chưa hợp lệ\nXin bạn hãy nhập lại giờ hát\n");
        printf("xin nhập giờ bắt đầu :");
        scanf("%d",&gioBatDau);
        printf("xin nhập giờ kết thúc :");
        scanf("%d",&gioKetThuc);
    } while (gioKetThuc<=gioBatDau||gioBatDau<12||gioKetThuc>23||gioBatDau>23||gioBatDau<0||gioKetThuc<0);

    gioHat=gioKetThuc-gioBatDau;

    if (gioHat==0)
    {
        printf("giờ chưa đủ để tính tiền");
    }else if (gioHat<=3)
    {
        if (gioBatDau>=14&&gioBatDau<=17)
        {
            gia=gioHat*150000*0.9;
        }else
        {
            gia=gioHat*150000;
        }
    }else if (gioBatDau>=14&&gioBatDau<=17)
    {
        gia=(3*150000 +(gioHat-3)*150000*0.7)*0.9;
    }else
    {
        gia=3*150000 +(gioHat-3)*150000*0.7;
    }
    printf("bạn cần thanh toán : %.2f đồng",gia);
}


//=========== CHỨC NĂNG 4 : TÍNH TIỀN ĐIỆN


void chucNang4(){
    // khai báo biến
    int dienTieuThu =0,tien=0;
    printf("hãy nhập số điện tiêu thụ hằng tháng :");
    scanf("%d",&dienTieuThu);
    //điều kiện giá điện
    if (dienTieuThu<=50)//bậc 1
    {
      tien=dienTieuThu*1678;
    }else if (dienTieuThu<=100)//bậc 2
    {
       tien=50*1678+(dienTieuThu-50)*1734;
    }else if (dienTieuThu<=200)//bậc 3
    {
       tien=50*1678+50*1734+(dienTieuThu-100)*2014;
    }else if (dienTieuThu<=300)//bậc 4
    {
       tien=50*1678+50*1734+100*2014+(dienTieuThu-200)*2536;
    }else if (dienTieuThu<=400)//bậc 5
    {
       tien=50*1678+50*1734+100*2014+100*2536+(dienTieuThu-300)*2834;
    }else //hết bậc
    {
       tien=50*1678+50*1734+100*2014+100*2536+100*2834+(dienTieuThu-400)*2927;
    }
    //hiển thị giá tiền
    printf("tiền cần phải đóng là :%d đồng",tien);   
}


//========= CHỨC NĂNG 5 : ĐỔI TIỀN


void chucNang5(){
    int Tien=0;
    int menhGia[]={500,200,100,50,20,10,5,2,1};
    int soTo[200]={0};
    printf("hãy nhập số tiền cần đổi :");
    scanf("%d",&Tien);

    for (int i = 0; i < 9; i++)
    {
        soTo[i]=Tien/menhGia[i];
        Tien-=menhGia[i]*soTo[i];
        
    }

    for (int i = 0; i < 9; i++)
    {
        if (soTo[i]>0)
        {
            printf("số tờ mệnh giá %d bạn cần đổi là : %d\n",menhGia[i],soTo[i]);
        }
    }
}


//========== CHỨC NĂNG 6 : TÍNH TIỀN VAY GIẢM THEO THÁNG 


void chucNang6 (){
    int tienVay=0;
    float tienTraGoc=0;
    float tienTraLai[13];
    float tienTraThang[12];
    float tienConLai[13];
        printf("xin mời nhập số tiền vay :");
        scanf("%d",&tienVay);
    tienTraGoc=(float)tienVay/12;
    tienTraLai[0]=tienVay*0.05;
    tienConLai[0]=tienVay;
    for (int i = 0; i < 12; i++)
    {
        tienTraThang[i]=tienTraGoc+tienTraLai[i];
        tienConLai[i+1]=tienConLai[i] -tienTraGoc;
        tienTraLai[i+1]=tienConLai[i+1]*0.05;
    }
    for (int i = 0; i < 12; i++)
    {
        printf("ở kì hạn %d,    lãi phải trả %.2f,    gốc phải trả :%.2f,   tiền phải trả :%.2f,   tiền còn lại :%.2f\n",i+1,tienTraLai[i],tienTraGoc,tienTraThang[i],tienConLai[i+1]);
    }
}


//=========== CHỨC NĂNG 7 : TÍNH TIỀN VAY CỐ ĐỊNH


void chucNang7() {
    double tyLe;
    printf("Nhap ty le vay (%%): ");
    scanf("%lf", &tyLe);

    if (tyLe <= 0 || tyLe > 100) {
        printf("Ty le vay khong hop le\n");
        return;
    }

    double giaXe = 500000000;
    double tienVay = giaXe * tyLe / 100;
    double traTruoc = giaXe - tienVay;

    double laiNam = 0.072;
    double laiThang = laiNam / 12;
    int soThang = 24 * 12;

    double heSo = pow(1 + laiThang, soThang);

    double traThang = tienVay * laiThang * heSo / (heSo - 1);

    printf("Tra truoc: %.0f VND\n", traTruoc);
    printf("Tra hang thang: %.0f VND\n", traThang);
}


//============ CHỨC NĂNG 8 : SẮP XẾP SINH VIÊN SINH VIÊN


struct sinhvien{
    char Ten[100];
    float diem;
    char hocLuc[25];
}Sv[50],temp;
void chucNang8(){
    int soLuong=0;
    printf("xin cho tôi biết số lượng sinh viện muốn nhập vào :");
    scanf("%d",&soLuong);
    while (soLuong>50)
    {
        printf("xin nhập dưới 50 sinh viên\n");
        printf("xin cho tôi biết số lượng sinh viện muốn nhập vào :");
        scanf("%d",&soLuong);
    }
        getchar();
    for (int i = 0; i < soLuong; i++)
    {
        printf("xin mời nhập họ và tên Sinh viên :");
        fgets(Sv[i].Ten, 100, stdin);
        printf("xin mời nhập điểm sinh viên");
        scanf("%f",&Sv[i].diem);
        getchar();
    }

    char loaiHocLuc [4][25]={"gioi","kha","trung binh","yeu"};
    
    for (int i = 0; i < soLuong; i++)
    {
        if (Sv[i].diem>=8)
        {
            strcpy(Sv[i].hocLuc, loaiHocLuc[0]);
        }else if (Sv[i].diem>=6.5)
        {
            strcpy(Sv[i].hocLuc, loaiHocLuc[1]);
        }else if (Sv[i].diem>=5)
        {
            strcpy(Sv[i].hocLuc, loaiHocLuc[2]);
        }else
        {
            strcpy(Sv[i].hocLuc, loaiHocLuc[3]);
        }
    }
    
    for (int i = 0; i < soLuong-1; i++)
    {
        for (int j =i+1; j < soLuong; j++)
        {
            if (Sv[i].diem<Sv[j].diem)
            {
                temp=Sv[i];
                Sv[i]=Sv[j];
                Sv[j]=temp;
            }
            
        }
        
    }

    printf(" DANH SÁCH SINH VIÊN :");

    for (int i = 0; i < soLuong; i++)
    {
        printf("Họ và Tên : %s\n",Sv[i].Ten);
        printf("Điểm trung bình :%.2f\n",Sv[i].diem);
        printf("Học Lực là : %s\n",Sv[i].hocLuc);
    }
}


//=========== CHỨC NĂNG 9 GAME POLY RANDOM


void chucNang9() {
    int user1, user2;
    int sys1, sys2;
    int match = 0;

    // Nhập 2 số từ người chơi
    do {
        printf("Nhap so thu nhat (01 - 15): ");
        scanf("%d", &user1);
        printf("Nhap so thu hai (01 - 15): ");
        scanf("%d", &user2);

        if (user1 < 1 || user1 > 15 || user2 < 1 || user2 > 15 || user1 == user2) {
            printf("Gia tri khong hop le! Vui long nhap lai.\n");
        }
    } while (user1 < 1 || user1 > 15 || user2 < 1 || user2 > 15 || user1 == user2);

    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    // Sinh 2 số ngẫu nhiên khác nhau
    sys1 = rand() % 15 + 1;
    do {
        sys2 = rand() % 15 + 1;
    } while (sys2 == sys1);

    // Hiển thị kết quả hệ thống
    printf("\nSo trung thuong cua he thong: %d - %d\n", sys1, sys2);

    // Kiểm tra trùng
    if (user1 == sys1 || user1 == sys2) match++;
    if (user2 == sys1 || user2 == sys2) match++;

    // Thông báo kết quả
    if (match == 0) {
        printf("Khong trung so nao. Chuc ban may man lan sau!\n");
    } else if (match == 1) {
        printf("Chuc mung ban da trung giai nhi!\n");
    } else if (match == 2) {
        printf("Chuc mung ban da trung giai nhat!\n");
    }
}


//=========== CHỨC NĂNG 10 : TÍNH TOÁN PHÂN SỐ


void chucNang10() {
    int tu1, mau1, tu2, mau2;
    int tu, mau;
    int chon;

    // Nhập phân số thứ nhất
    do {
        printf("Nhap tu so 1: ");
        scanf("%d", &tu1);
        printf("Nhap mau so 1 (khac 0): ");
        scanf("%d", &mau1);
    } while (mau1 == 0);

    // Nhập phân số thứ hai
    do {
        printf("Nhap tu so 2: ");
        scanf("%d", &tu2);
        printf("Nhap mau so 2 (khac 0): ");
        scanf("%d", &mau2);
    } while (mau2 == 0);

    // Menu phép toán
    printf("\n===== PHEP TOAN PHAN SO =====\n");
    printf("1. Cong\n");
    printf("2. Tru\n");
    printf("3. Nhan\n");
    printf("4. Chia\n");
    printf("Chon: ");
    scanf("%d", &chon);

    switch (chon) {
        case 1:
            tu = tu1 * mau2 + tu2 * mau1;
            mau = mau1 * mau2;
            break;
        case 2:
            tu = tu1 * mau2 - tu2 * mau1;
            mau = mau1 * mau2;
            break;
        case 3:
            tu = tu1 * tu2;
            mau = mau1 * mau2;
            break;
        case 4:
            if (tu2 == 0) {
                printf("Khong the chia cho 0!\n");
                return;
            }
            tu = tu1 * mau2;
            mau = mau1 * tu2;
            break;
        default:
            printf("Lua chon khong hop le!\n");
            return;
    }

    // Rút gọn phân số
    int a = tu, b = mau;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    tu /= a;
    mau /= a;

    // Chuẩn hóa dấu
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }

    printf("\nKet qua = %d/%d\n", tu, mau);
}

//================== MAIN MENU ==================//
int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                chucNang1();
                pauseScreen();
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                chucNang2();
                pauseScreen();
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                chucNang3();
                pauseScreen();
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                chucNang4();
                pauseScreen();
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                chucNang5();
                pauseScreen();
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                chucNang6();
                pauseScreen();
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                chucNang7();
                pauseScreen();
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                chucNang8();
                pauseScreen();
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                chucNang9();
                pauseScreen();
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                chucNang10();
                pauseScreen();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

return 0;
}