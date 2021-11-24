#include <iostream>
#include <queue>

using namespace std;

//binary tree node
struct btNode
{
    int data;
    btNode *leftchild;
    btNode *rightchild;
};

class binaryTree
{
private:
    btNode *root;

public:
    binaryTree()
    {
        root = NULL;
    }

    void insert(int data)
    {

        if (root == NULL)
        {
            //the first element -- will be root
            btNode *newData = new btNode;
            newData->data = data;
            newData->leftchild = NULL;
            newData->rightchild = NULL;

            root = newData;
        }
        else
        {

            //queue
            queue<btNode *> temporaryStorage;

            //pushing node
            temporaryStorage.push(root);

            //now triversing
            while (1)
            {
                btNode *temp = temporaryStorage.front();
                temporaryStorage.pop();

                if (temp->leftchild == NULL)
                {

                    btNode *newData = new btNode;
                    newData->data = data;
                    newData->leftchild = NULL;
                    newData->rightchild = NULL;

                    temp->leftchild = newData;

                    //if inserted
                    break;
                }

                if (temp->rightchild == NULL)
                {
                    btNode *newData = new btNode;
                    newData->data = data;
                    newData->leftchild = NULL;
                    newData->rightchild = NULL;

                    temp->rightchild = newData;

                    //if inserted
                    break;
                }

                //if the insertion was not done mean level was complete
                temporaryStorage.push(temp->leftchild);
                temporaryStorage.push(temp->rightchild);
            }
        }
    }

    void display()
    {

        //queue
        queue<btNode *> temporaryStorage;

        //pushing node
        temporaryStorage.push(root);

        //now triversing
        while (1)
        {
            btNode *temp = temporaryStorage.front();
            temporaryStorage.pop();

            cout << "Parent : " << temp->data << endl;

            if (temp->leftchild == NULL)
            {
                //if any left is null mean ended
                break;
            }

            cout << "left child : " << temp->leftchild->data << endl;

            if (temp->rightchild == NULL)
            {
                //if any left is null mean ended
                break;
            }

            cout << "right child : " << temp->rightchild->data << endl;

            //if the insertion was not done mean level was complete
            temporaryStorage.push(temp->leftchild);
            temporaryStorage.push(temp->rightchild);

            cout << endl;
        }
    }

    bool replace(int oldData, int newData)
    {

        //queue
        queue<btNode *> temporaryStorage;

        //pushing node
        temporaryStorage.push(root);

        //now triversing
        while (1)
        {
            btNode *temp = temporaryStorage.front();
            temporaryStorage.pop();

            if (temp->data == oldData)
            {
                temp->data = newData;
                return true;
            }

            if (temp->leftchild == NULL)
            {
                //if any left is null mean ended
                return false; //not found
            }

            //mean left data exist
            if (temp->leftchild->data == oldData)
            {

                temp->leftchild->data = newData;
                return true;
            }

            if (temp->rightchild == NULL)
            {
                //if any left is null mean ended
                return false;
            }

            if (temp->rightchild->data == oldData)
            {

                temp->rightchild->data = newData;
                return true;
            }

            //if the insertion was not done mean level was complete
            temporaryStorage.push(temp->leftchild);
            temporaryStorage.push(temp->rightchild);
        }
    }
};

int main()
{

    binaryTree bt;

    for (int i = 0; i < 10; i++)
    {
        bt.insert(i);
    }

    bt.display();

    system("pause");

    cout<<endl;

    cout << "replacing 9 with 90" << endl;
     bt.replace(9, 90);

    system("pause");

    cout<<endl;

    bt.display();

    return 0;
}
