#include "main.h"

int main()
{
    //创建通讯录
    AddressBooks abs;
    //初始化通讯录中人数
    abs.m_Size = 0;
    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;

        switch (select)
        {
        case 1: //1、添加联系人
            addPerson(&abs);
            break;
        case 2: //2、显示联系人
            showPerson(&abs);
            break;
        case 3: //3、删除联系人
            deletePerson(&abs);
            break;
        case 4: //4、查找联系人
            findPerson(&abs);
            break;
        case 5: //5、修改联系人
            modifyPerson(&abs);
            break;
        case 6: //6、清空联系人
            cleanPerson(&abs);
            break;
        case 0: //0、退出通讯录
            cout << "欢迎下次使用" << endl;
            return 0;
            break;       
        default:
            break;
        }

    }
    return 0;
}