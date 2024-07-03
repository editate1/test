#include <iostream>
#include <cmath>  // For sqrt function

using namespace std;

int main() {
    int n;
    cout << "Nhap gia tri n: ";
    cin >> n;

    bool Kiem_tra = true;

    if (n < 2) {
        Kiem_tra = false;  // Các số nhỏ hơn 2 không phải là số nguyên tố
    }
    else if (n > 2) {
        if (n % 2 == 0) {
            Kiem_tra = false;  // Loại bỏ các số chẵn lớn hơn 2
        } else {
            for (int i = 3; i <= sqrt(n); i += 2) {                                 // chạy từ 3 vì ngoài 2 là số nguyên tố, tất cả các số chẵn --> đều không phải số nguyên tố --> i+=2 và chỉ chạy đến căn của n
                                                                                    // giả sử: n= a x b --> vd: 6 = 2 x 3
                                                                                    // giả sử n có ước nhỏ hơn căn n (2,44) là 2 --> cx phải có ước lớn hơn căn n (là 3) --> a(2) <= căn n(2.44) <= b(3)
                                                                                    //nếu không tìm thấy ước trong đoạn 2 đến căn n --> n không có ước lớn hơn căn n --> n là số nguyên tố (vì trong đoạn 2 đến căn n --> đã không có số chia hết cho i)
                if (n % i == 0) {
                    Kiem_tra = false;  // Nếu tìm thấy ước số, n không phải là số nguyên tố
                    break;
                }
            }
        }
    }

    if (Kiem_tra) {
        cout << n << " la so nguyen to" << endl;
    } else {
        cout << n << " khong phai la so nguyen to" << endl;
    }

    return 0;
}
