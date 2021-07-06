//
//  main.cpp
//  18_Inheritance
//
//  Created by 세광 on 2021/07/06.
//

// 공통적인 멤버를 관리할 때 부모 class를 사용함으로써 효율적으로 관리할 수 있음

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    // string 형변환 연산자 오버로딩
    operator string() {
        return "사진";
    }
};

class Message {
public:
    Message(int sendTime, string sendName) {
        this->sendTime = sendTime;
        this->sendName = sendName;
    }
    
    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }
    
private:
    int sendTime;
    string sendName;
};

class Textmessage : public Message {
public:
    Textmessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
        this->text = text;
    }
    
    string GetText() const { return text; }
    
private:
    string text;
};

class ImageMessage : public Message {
public:
    ImageMessage(int sendTime, string sendName, Image *image) : Message(sendTime, sendName) {
        this->image = image;
    }
    
    Image *GetImage() const { return image; }
    
private:
    Image *image;
};

int main() {
    Image *p_dogImage = new Image();
    Textmessage *hello = new Textmessage(10, "두들", "안녕");
    ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);
    
    cout << "보낸 시간: " << hello->GetSendTime() << endl;
    cout << "보낸 사람: " << hello->GetSendName() << endl;
    cout << "내용: " << hello->GetText() << endl;
    cout << endl;
    
    cout << "보낸 시간: " << dog->GetSendTime() << endl;
    cout << "보낸 사람: " << dog->GetSendName() << endl;
    cout << "내용: " << (string)*dog->GetImage() << endl;
    cout << endl;
    
    delete hello;
    delete dog;
    delete p_dogImage;
}
