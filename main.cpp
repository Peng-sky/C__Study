//
// Created by Peng on 2022-12-03.
//
#include "iostream"
#include "string"

#define MAX 1000

using namespace std;


struct Person {
    string name;
    int sex;
    int age;
    string phone;
    string addr;
};

struct Addressbooks {
    struct Person personArray[MAX];
    int size;
};

void showMain() {
    cout << "**********************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "**********************" << endl;
}

void addPerson(Addressbooks *abs) {
    if (abs->size == MAX) {
        cout << "通讯录已满" << endl;
    } else {
        // add contact
        string name;
        cout << "please input name " << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;
        // sex
        cout << "please input sex " << endl;
        cout << "1 boy " << endl;
        cout << "2 girl " << endl;
        int sex = 0;

        while (true) {
            // if 1 or 2 exit, or redo
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->size].sex = sex;
                break;
            }
            cout << "please try again" << endl;
        }

        // age
        cout << "age is ? " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->size].age = age;

        // phone
        cout << "phone number is ? " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->size].phone = phone;

        //address
        // phone
        cout << "address is ? " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->size].addr = address;

        abs->size++;

        cout << "add correct " << endl;
        system("pause");
        system("cls");
    }
}

void showPerson(Addressbooks *abs) {
    if (abs->size == 0) {
        cout << "no person" << endl;
    } else {
        for (int i = 0; i < abs->size; ++i) {
            cout << "name = " << abs->personArray[i].name << "\t";
            cout << "sex = " << (abs->personArray[i].sex == 1 ? "boy" : "girl") << "\t";
            cout << "age = " << abs->personArray[i].age << "\t";
            cout << "phone = " << abs->personArray[i].phone << "\t";
            cout << "address = " << abs->personArray[i].addr << endl;
        }
    }
    system("pause");
    system("cls");
}

int isExist(Addressbooks *abs, string name) {
    for (int i = 0; i < abs->size; ++i) {
        if (abs->personArray[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs) {
    cout << "please input who you want to delete" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "dont found" << endl;
    } else {
        for (int i = ret; i < abs->size; ++i) {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
            abs->size--;
            cout << "delete success" << endl;
        }
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks *abs) {
    string name;
    cout << "please input name" << endl;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "can not found" << endl;
    } else {
        Person person = abs->personArray[ret];
        cout << "name = " << person.name << "\t";
        cout << "age = " << person.age << "\t";
        cout << "sex = " << person.sex << "\t";
        cout << "phone = " << person.phone << "\t";
        cout << "addr = " << person.addr << "\t";
    }
    system("pause");
    system("cls");
}

void changePerson(Addressbooks *abs) {
    string name;
    cout << "please input name" << endl;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "can not found" << endl;
    } else {
        string nameString;
        cout << "please input nameString" << endl;
        cin >> nameString;
        abs->personArray[ret].name = nameString;

        int sex;
        cout << "please input sex" << endl;
        cout << "1 boy" << endl;
        cout << "2 girl" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].sex = sex;
                break;
            }
            cout << "please re input " << endl;
        }

        int age;
        cout << "please input age" << endl;
        cin >> age;
        abs->personArray[ret].age = age;

        string phone;
        cout << "please input phone" << endl;
        cin >> phone;
        abs->personArray[ret].name = phone;

        string addr;
        cout << "please input addr" << endl;
        cin >> addr;
        abs->personArray[ret].addr = addr;
    }
    system("pause");
    system("cls");
}

void deleteAll(Addressbooks *abs) {
    abs->size = 0;
    cout << "delete success" << endl;
    system("pause");
    system("cls");
}

int* func() {
    int a =0;
    return &a;
}

int main() {
    Addressbooks abs;
    abs.size = 0;
    int select = 0;
    while (true) {
        showMain();
        cin >> select;
        switch (select) {
            case 1: //add
                addPerson(&abs); //地址传递， 才能正真修改传入的数据， 可以修饰实参
                break;
            case 2: //show
                showPerson(&abs);
                break;
            case 3: //delete
                deletePerson(&abs);
                break;
            case 4: // find
                findPerson(&abs);
                break;
            case 5: // change
                changePerson(&abs);
                break;
            case 6: // delete all
                deleteAll(&abs);
                break;
            case 0: // exit
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
        }
    }
}