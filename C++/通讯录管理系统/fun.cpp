#include "main.h"


/*菜单展示*/
void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人   *****" << endl;
	cout << "*****  2、显示联系人   *****" << endl;
	cout << "*****  3、删除联系人   *****" << endl;
	cout << "*****  4、查找联系人   *****" << endl;
	cout << "*****  5、修改联系人   *****" << endl;
	cout << "*****  6、清空联系人   *****" << endl;
	cout << "*****  0、退出通讯录   *****" << endl;
	cout << "***************************" << endl;
}

/*添加联系人*/
void addPerson(AddressBooks *abs)
{
    /*判断电话本是否已经满了*/
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {        
        cout << "请输入姓名：";
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        
        cout << "请输入性别：" << endl << "1--男 2--女";
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入";
            }
            
        }

        cout << "请输入年龄：";
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话：";
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入住址：";
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address; 

        /*更新通讯录人数*/
        abs->m_Size++;

        cout << "添加成功" << endl;
    
    }
    
}

/*显示联系人*/
void showPerson(AddressBooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
        
    }
    
}

/*判断联系人是否存在*/
int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
        
    }
    return -1;
}

/*删除指定联系人信息*/
void deletePerson(AddressBooks *abs)
{
    cout << "请输入要删除的联系人：";
    string name;
    cin >> name;

    /*判断联系人是否存在*/
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人"  << endl;
    }
    
}

/*查找联系人*/
void findPerson(AddressBooks *abs)
{
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

/*修改联系人*/
void modifyPerson(AddressBooks *abs)
{
    cout << "请输入要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        
        cout << "请输入性别：" << endl << "1--男 2--女";
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入";
            }
            
        }

        cout << "请输入年龄：";
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "请输入电话：";
        string phone = "";
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "请输入住址：";
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    
}

/*清空联系人*/
void cleanPerson(AddressBooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
}