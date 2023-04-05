#ifndef __MAIN__
#define __MAIN__
#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

/*联系人结构体*/
struct Person
{
    string m_Name;  //姓名
    int m_Sex;      //性别:1男 2女
    int m_Age;      //年龄
    string m_Phone; //电话
    string m_Addr;  //地址
};

/*通讯录结构体*/
struct AddressBooks
{
    struct Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size;                     //通讯录中人员个数
};
#endif

/*菜单展示*/
void showMenu();
/*添加联系人*/
void addPerson(AddressBooks *abs);
/*显示联系人*/
void showPerson(AddressBooks *abs);
/*删除指定联系人信息*/
void deletePerson(AddressBooks *abs);
/*查找联系人*/
void findPerson(AddressBooks *abs);
/*修改联系人*/
void modifyPerson(AddressBooks *abs);
/*清空联系人*/
void cleanPerson(AddressBooks *abs);

