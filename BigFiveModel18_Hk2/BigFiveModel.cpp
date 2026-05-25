#include<iostream>
#include<string.h>

using namespace std;

class OCEAN{
    private:
        int MucDo;
    public:
        OCEAN(){

        }
        virtual ~OCEAN(){

        }
        void NhapMucDo(){
            cin >> MucDo;
        };
        virtual void XuatMucDo() = 0;
        virtual void NhanXet() = 0;
        int GetMucDo(){
            return MucDo;
        };
};
class NhomO: public OCEAN{
    private:
    public:
        NhomO(){

        }
        ~NhomO(){

        }
        void XuatMucDo() override {
            cout << "O" << this->GetMucDo();
        }
        void NhanXet()override{
            cout << "Sẵn sàng trải nghiệm (O)";
            if (this->GetMucDo() >= 70){
                cout << "Người có điểm cao ở yếu tố này thường là  người thích những ý tưởng mới,"  ;
                cout << "thích hiểu biết nhiều lĩnh vựcnhưng đồng thời cũng thích tự do, không thích bị ràng buộc..." << endl;
            } else if (this->GetMucDo() <= 30){
                cout << "Người có điểm thấp ở yếu tố này thường khá bảo thủ, khó tiếp nhận những ý tưởng mới, lạ." ;
                cout << "Họ thích sự ổn định, quen thuộc và thực tế." << endl;
            } else cout << "Khong Xac dinh ro. ";
        }
};
class NhomC: public OCEAN{
    private:
    public:
        NhomC(){};
        ~NhomC(){};
        void XuatMucDo() override {
            cout << "C" << this->GetMucDo();
        }
        void NhanXet()override{
            cout << "Tự chủ tận tâm (C)";
            if (this->GetMucDo() >= 70){
                cout << "Người có điểm cao ở yếu tố này thường là người chăm chỉ, "  ;
                cout << "năng chịu áp lực tốt. Họ thường là người gắn bó, trung thành với tổ chức." << endl;
            } else if (this->GetMucDo() <= 30){
                cout << "Người có điểm thấp ở yếu tố này thường dễ bỏ cuộc, khả năng chịu áp " ;
                cout << "lực, tuân thủ kỷ luật của tổ chức kém." << endl;
            } else cout << "Khong Xac dinh ro. ";
        }
};
class NhomE: public OCEAN{
    private:
    public:
        NhomE(){};
        ~NhomE(){};
        void XuatMucDo() override {
            cout << "E" << this->GetMucDo();
        }
        void NhanXet()override{
            cout << "Hướng ngoại (E)";
            if (this->GetMucDo() >= 70){
                cout << "Người có điểm cao ở yếu tố này thường là người nhiệt tình, năng "  ;
                cout << "động, giao tiếp tốt, thích thể hiện bản thân." << endl;
            } else if (this->GetMucDo() <= 30){
                cout << "Người có điểm thấp ở yếu tố này thường ngại giao tiếp, không thích" ;
                cout << "sự nổi bật, thích được làm việc độc lập." << endl;
            } else cout << "Khong Xac dinh ro. ";
        }
};
class NhomA: public OCEAN{
    private:
    public:
        NhomA(){};
        ~NhomA(){};
        void XuatMucDo() override {
            cout << "A" << this->GetMucDo();
        }
        void NhanXet()override{
            cout << "Hòa đồng dễ chịu (A)";
            if (this->GetMucDo() >= 70){
                cout << "Người có điểm cao ở yếu tố này thường thân thiện, cởi mở, đồng cảm"  ;
                cout <<'với mọi người nhưng nhiều khi “thiếu chính kiến." '<< endl;
            } else if (this->GetMucDo() <= 30){
                cout << "Người có điểm thấp thường đặt lợi ích của bản thân lên trên, ít" ;
                cout << "đồng cảm, chia sẻ với đồng nghiệp, có tính cạnh tranh cao." << endl;
            } else cout << "Khong Xac dinh ro. ";
        }
};
class NhomN: public OCEAN{
    private:
    public:
        NhomN(){};
        ~NhomN(){};
        void XuatMucDo() override {
            cout << "N" << this->GetMucDo();
        }
        void NhanXet()override{
            cout << "Bất ổn cảm xúc (N)";
            if (this->GetMucDo() >= 70){
                cout << "Người có điểm cao ở yếu tố này thường có các cảm xúc tiêu cực"  ;
                cout <<'như: lo lắng, bực bội, tự ti, yếu đuối và khả năng chịu áp lực kém." '<< endl;
            } else if (this->GetMucDo() <= 30){
                cout << "Người có điểm thấp ở yếu tố này thường kiểm soát được cảm xúc, ứng" ;
                cout << "phó với căng thẳng tốt, ít bị bên ngoài ảnh hưởng đến tâm trạng của bản thân." << endl;
            } else cout << "Khong Xac dinh ro. ";
        }
};
class Nguoi{
    private:
        OCEAN** TinhCach;
    public:
        Nguoi(){
            TinhCach = new OCEAN*[5];
            TinhCach[0] = new NhomO;
            TinhCach[1] = new NhomC;
            TinhCach[2] = new NhomE;
            TinhCach[3] = new NhomA;
            TinhCach[4] = new NhomN;
        };
        ~Nguoi(){
            for (int i = 0 ; i < 5; i++){
                delete TinhCach[i];
            }
            delete[] TinhCach;
        };
        void NhapKetQuaDanhGia(){
            for (int i = 0; i < 5; i++){
                TinhCach[i]->NhapMucDo();
            }
        }
        void XuatKetQuaDanhGia(){
            for(int i = 0; i < 5; i++){
                TinhCach[i]->XuatMucDo();
            }
        };
        void XuatNhanXetTinhCach(){
            for (int i =0; i < 5; i++){
                TinhCach[i]->NhanXet(); 
            }
        }
        bool DanhGiaNguyCo(){
            if (TinhCach[1]->GetMucDo() <= 30 ||  TinhCach[4] ->GetMucDo() >= 70 ){
                return true;
            } return false;
        }
};

int main(){
    // cau 1
    Nguoi NguoiDauTien;
    NguoiDauTien.NhapKetQuaDanhGia();
    // Cau 2
    Nguoi* DSNguoi;
    int n;
    cin >> n;
    DSNguoi = new Nguoi[n];
    for (int i = 0; i < n; i++){
        DSNguoi[i].NhapKetQuaDanhGia();
    }
    // Cau 3
    int chon;
    cin >> chon;
    DSNguoi[chon].XuatNhanXetTinhCach();
    // Cau 4
    cout << "Danh sach nhung nguoi co nguy co: " << endl;
    for (int i = 0; i < n; i++){
        if (DSNguoi[i].DanhGiaNguyCo()){
            cout << "Nguoi so thu tu: " << i + 1 << endl;
        }
    }

    delete[] DSNguoi;

    return 0;
}