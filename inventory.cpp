#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Product
{
public:
    int id;
    string name;
    double price;
    int quantity;
    Product *next;
    Product *hashNext;
};

Product *head = NULL;
const int TABLE_SIZE = 10;
Product *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int id)
{
    return id % TABLE_SIZE;
}

Product *findProduct(int id)
{
    int index = hashFunction(id);
    Product *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }

        temp = temp->hashNext;
    }

    return NULL;
}

void addProduct()
{
    Product *newProduct = new Product();

    cout << "Enter product ID: ";
    cin >> newProduct->id;

    if (findProduct(newProduct->id) != NULL)
    {
        cout << "Product ID already exists. Product was not added." << endl;
        delete newProduct;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter product name: ";
    getline(cin, newProduct->name);

    cout << "Enter product price: ";
    cin >> newProduct->price;

    cout << "Enter product quantity: ";
    cin >> newProduct->quantity;

    newProduct->next = head;
    head = newProduct;

    int index = hashFunction(newProduct->id);
    newProduct->hashNext = hashTable[index];
    hashTable[index] = newProduct;

    cout << "Product added successfully." << endl;
}

void searchProduct()
{
    int id;

    cout << "Enter product ID to search: ";
    cin >> id;

    Product *product = findProduct(id);

    if (product == NULL)
    {
        cout << "Product with ID " << id << " not found." << endl;
        return;
    }

    cout << "Product found:" << endl;
    cout << "ID: " << product->id << endl;
    cout << "Name: " << product->name << endl;
    cout << "Price: " << product->price << endl;
    cout << "Quantity: " << product->quantity << endl;
}

void updateProduct()
{
    int id;

    cout << "Enter product ID to update: ";
    cin >> id;

    Product *product = findProduct(id);

    if (product == NULL)
    {
        cout << "Product with ID " << id << " not found." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new product name: ";
    getline(cin, product->name);

    cout << "Enter new product price: ";
    cin >> product->price;

    cout << "Enter new product quantity: ";
    cin >> product->quantity;

    cout << "Product updated successfully." << endl;
}

void displayProducts()
{
    Product *temp = head;

    if (temp == NULL)
    {
        cout << "No products available." << endl;
        return;
    }

    cout << "All Available Products:" << endl;

    while (temp != NULL)
    {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "-------------------" << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nE-Commerce Product Catalog and Inventory System" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. Search Product by ID" << endl;
        cout << "3. Update Product Details" << endl;
        cout << "4. Display All Products" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct();
            break;

        case 2:
            searchProduct();
            break;

        case 3:
            updateProduct();
            break;

        case 4:
            displayProducts();
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
