#include<iostream>
#include<string.h>

using namespace std;

/*
Bài học nhận ra:
1. Có thể phân lớp ra thành dạng nhỏ, nhiều lớp khác nhau, nhận diện bằng một hàm trả về thông tin chính của lớp đó.
Việc này có thể làm đơn giản hóa thuật toán cần phải xử lý. Thay vì cần một hàm lớn để xử lý cho mọi trường hợp của lớp bé
thì tại mỗi lớp bé, sẽ có một hàm riềng (được override) để xử lý chỉ riêng cho trường hợp của hàm đó.

2. Khi gọi hàm với một đối tượng có chứa con trỏ được cấp phát vùng nhớ, cần phải chỉnh biến đó về dạng tham chiếu, nhằm tránh 
việc đối tượng bị copy nhân đôi, tức là tạo được một con trỏ khác cũng trỏ vào địa chỉ y hệt như đối tượng cũ. Bởi vì khi hàm 
này chạy xong, đối tượng được copy cũng bị hủy bỏ, dẫn đến vùng nhớ cũng bị hủy bỏ theo đó, khi ta gọi lại biến đó như bình thường
thì dữ liệu sẽ không còn ở đó nữa.

3. Cần phải có một sơ đồ lớp cụ thể, chi tiết, nhằm có thể căn chỉnh phân bố thời gian cho từng lớp, cho từng hàm khác nhau
trong chương trình, như bài vừa rồi, ta quên mất hay không biết về việc cần phải có một lớp người nhằm thu thập thông tin 
về người đó, nhằm ứng dụng trong câu 3.

4. Lỗi lặt vặt: Trong hàm nhập của người, sau khi cin giá trị của biến Rh, thì ta lại không lưu giá trị vào đối tượng Nhóm máu.
Trong câu 2, Chạy chương trình mà chưa có hàm nhập, nên chương trình sẽ bị lõi.

5. Hàm thuần ảo sẽ biến lớp đó thành lớp thuẩn ảo, nên không có đối tượng nào được phép tạo ra, vì vậy, chúng ta chỉ có thể 
dùng con trỏ để xử lý.


*/ 
class NhomMau{
    private:
        bool HeRh;
    public:
        NhomMau(){

        }
        virtual ~NhomMau(){

        }
        bool GetMauRh(){
            return HeRh;
        }
        void setMauRh(bool Rh){
            this->HeRh = Rh;
        }
        virtual string GetMauOAB() = 0;
        virtual bool KiemTraTuongThich(NhomMau*) = 0;
        virtual bool KiemTraDiTruyen(NhomMau*, NhomMau*) = 0; 
};
class NhomO: public NhomMau{
    public:
        NhomO(){

        }
        ~NhomO(){

        }
        string GetMauOAB()override{
            return "O";
        }
        bool KiemTraTuongThich(NhomMau* MauCho)override{
            if (MauCho->GetMauOAB() == "O"){
                if (this->GetMauRh()){ return true;}
                else if (MauCho->GetMauRh() == false){
                    return true;
                } return false;
            } return false;
        }
        bool KiemTraDiTruyen(NhomMau* Cha, NhomMau* Me)override{
            if (Cha->GetMauOAB() == "AB" | Me->GetMauOAB() == "AB"){
                return false;
            } else if (this->GetMauRh() == false){
                if (Me->GetMauRh()) return false;
            } return true;
        }
};
class NhomA: public NhomMau{
    public:
        NhomA(){

        };
        ~NhomA(){

        }
        string GetMauOAB()override{
            return "A";
        }
        bool KiemTraTuongThich(NhomMau* MauCho)override{
            if (MauCho->GetMauOAB() == "O" | MauCho->GetMauOAB() == "A"){
                if (this->GetMauRh()){ return true;}
                else if (MauCho->GetMauRh() == false){
                    return true;
                } return false;
            } return false;
        }
        bool KiemTraDiTruyen(NhomMau* Cha, NhomMau* Me)override{
            if (Cha->GetMauOAB() == "B" || Cha->GetMauOAB() == "O"){
                if (Me->GetMauOAB() == "O" || Me->GetMauOAB() == "B" ){
                    return false;
                }
            } else if (this->GetMauRh() == false){
                if (Me->GetMauRh()) return false;
            } return true;
        }
};
class NhomB: public NhomMau{
    public:
        NhomB(){

        };
        ~NhomB(){

        }
        string GetMauOAB()override{
            return "B";
        }
        bool KiemTraTuongThich(NhomMau* MauCho)override{
            if (MauCho->GetMauOAB() == "O" | MauCho->GetMauOAB() == "B"){
                if (this->GetMauRh()){ return true;}
                else if (MauCho->GetMauRh() == false){
                    return true;
                } return false;
            } return false;
        }
        bool KiemTraDiTruyen(NhomMau* Cha, NhomMau* Me)override{
            if (Cha->GetMauOAB() == "A" || Cha->GetMauOAB() == "O"){
                if (Me->GetMauOAB() == "O" || Me->GetMauOAB() == "A" ){
                    return false;
                }
            } else if (this->GetMauRh() == false){
                if (Me->GetMauRh()) return false;
            } return true;
        }
};
class NhomAB: public NhomMau{
    public:
        NhomAB(){

        };
        ~NhomAB(){

        }
        string GetMauOAB(){
            return "AB";
        }
        bool KiemTraTuongThich(NhomMau* MauCho) override{
            if (this->GetMauRh()){ return true;}
                else if (MauCho->GetMauRh() == false){
                    return true;
                } return false;
        }
        bool KiemTraDiTruyen(NhomMau* Cha, NhomMau* Me)override{
            if (Cha->GetMauOAB() == "O" || Me->GetMauOAB() == "O"){
                return false;
            } else if (Cha->GetMauOAB() == Me->GetMauOAB()){
                if (Cha->GetMauOAB() == "A" || Cha->GetMauOAB() == "B"){
                    return false;
                }
            } else if (this->GetMauRh() == false){
                if (Me->GetMauRh()) return false;
            } return true;
        }
};
class Nguoi{
    private:
        string HoTen;
        int Namsinh;
        NhomMau* NhomMauBN;
    public:
        Nguoi(){
        }
        ~Nguoi(){
            delete NhomMauBN;
        }
        void Nhap(){
            cin.ignore();
            getline(cin, HoTen);
            cin >> Namsinh;
            string MauMau;
            cin.ignore();
            cin >> MauMau;
            if ( MauMau == "O"){
                NhomMauBN = new NhomO;
            }
            if (MauMau == "A"){
                NhomMauBN = new NhomA;
            }
            if (MauMau == "B"){
                NhomMauBN = new NhomB;
            }
            if (MauMau == "AB"){
                NhomMauBN = new NhomAB;
            }
            bool MauRh;
            cin >> MauRh;
            this->NhomMauBN->setMauRh(MauRh);
        }
        void Xuat(){
            cout << HoTen << endl;
            cout << Namsinh << endl;
            cout << "Nhom Mau: " << NhomMauBN->GetMauOAB();
            if (NhomMauBN->GetMauRh()){
                cout << "+";
            }else {
                cout << "-";
            }
        }
        bool KiemTraTuongThich(Nguoi Khac){
            return this->NhomMauBN->KiemTraTuongThich(Khac.NhomMauBN);
        }
        bool KiemTraDiTruyen(Nguoi Cha, Nguoi Me){
            return this->NhomMauBN->KiemTraDiTruyen(Cha.NhomMauBN, Me.NhomMauBN);
        }

};
int main(){
    // Cau 1
    int n;
    cin >> n;
    Nguoi* DSNguoi;
    DSNguoi = new Nguoi[n];
    string NhanMau;
    for (int i = 0; i < n; i++){
        DSNguoi[i].Nhap();
    }
    
    // Cau 2
    Nguoi* DSGiaDinh;
    DSGiaDinh = new Nguoi[3];
    for (int i = 0; i < 3; i++){
        DSGiaDinh[i].Nhap();
    }
    bool Ketqua = DSGiaDinh[0].KiemTraDiTruyen(DSGiaDinh[1], DSGiaDinh[2]);
    

    // Cau 3
    int Chon = 4;
    bool PhuHop[n];
    for (int i = 0; i < n; i++){
        if (DSNguoi[4].KiemTraTuongThich(DSNguoi[i])){
            if (i != 4){
                DSNguoi[i].Xuat();
            }
        }
    }



    delete[] DSNguoi;
    delete[] DSGiaDinh;
    return 0;
}