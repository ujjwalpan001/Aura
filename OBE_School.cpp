#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 100

using namespace std;

// Schools structure
struct Schools {
    int id;
    string schools_code;
    string schools_name;
    string schools_address;
    string schools_email;
    string schools_website;
};

// Global vector to store schools data and a counter
vector<Schools> schoolss;
int schools_count = 0;

// File name for storing the details
const char* FILE_NAME = "schools_setting.txt";

// Function declarations
void Aura_schools_create();
void Aura_schools_update();
void Aura_schools_retrieve();
void Aura_schools_delete();
void Aura_schools_storing();
void Aura_schools_sortbycode();
void Aura_schools_searchbycode();

// Function to load data from the file into the schoolss vector
void load_from_file() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "\n🌐 [INFO] No data file found. Starting fresh.\n";
        return;
    }
    schoolss.clear();
    Schools s;
    while (file >> s.id >> s.schools_code >> s.schools_name >> s.schools_address >> s.schools_email >> s.schools_website) {
        schoolss.push_back(s);
    }
    file.close();
    schools_count = schoolss.size();
}

// Function to save data to the file
void Aura_schools_storing() {
    ofstream file(FILE_NAME);
    if (!file) {
        cout << "";
        return;
    }
    for (const auto& s : schoolss) {
        file << s.id << " " << s.schools_code << " " << s.schools_name << " " << s.schools_address << " " << s.schools_email << " " << s.schools_website << "\n";
    }
    file.close();
}

// Function to create a schools record
void Aura_schools_create() {
    if (schools_count >= MAX) {
        cout << "\n🔴 [ERROR] Schools list is at full capacity!\n";
        return;
    }
    Schools s;
    cout << "\n🌟 --- Add New School --- 🌟\n";
    cout << "Enter Schools ID: ";
    cin >> s.id;
    cout << "Enter Schools Code: ";
    cin >> s.schools_code;
    cout << "Enter Schools Name: ";
    cin >> s.schools_name;
    cout << "Enter Schools Address: ";
    cin >> s.schools_address;
    cout << "Enter Schools Email: ";
    cin >> s.schools_email;
    cout << "Enter Schools Website: ";
    cin >> s.schools_website;
    schoolss.push_back(s);
    schools_count++;
    Aura_schools_storing();
    cout << "\n✅ [SUCCESS] School added successfully!\n";
}

// Function to update a schools record
void Aura_schools_update() {
    int id;
    cout << "\n🔄 --- Update School Information --- 🔄\n";
    cout << "Enter Schools ID to update: ";
    cin >> id;
    for (auto& s : schoolss) {
        if (s.id == id) {
            cout << "Enter new Schools Code: ";
            cin >> s.schools_code;
            cout << "Enter new Schools Name: ";
            cin >> s.schools_name;
            cout << "Enter new Schools Address: ";
            cin >> s.schools_address;
            cout << "Enter new Schools Email: ";
            cin >> s.schools_email;
            cout << "Enter new Schools Website: ";
            cin >> s.schools_website;
            Aura_schools_storing();
            cout << "\n✅ [SUCCESS] School updated successfully!\n";
            return;
        }
    }
    cout << "\n⚠ [ERROR] School with ID " << id << " not found.\n";
}

// Function to retrieve all schools records
void Aura_schools_retrieve() {
    cout << "\n📒 --- Schools Directory --- 📒\n";
    if (schoolss.empty()) {
        cout << "\n📂 [INFO] No schools data found.\n";
        return;
    }
    for (const auto& s : schoolss) {
        cout << "📌 ID: " << s.id << "\n🆔 Code: " << s.schools_code << "\n🏫 Name: " << s.schools_name << "\n📍 Address: " << s.schools_address << "\n📧 Email: " << s.schools_email << "\n🌐 Website: " << s.schools_website << "\n";
        cout << "🔹-----------------------------🔹\n";
    }
}

// Function to delete a schools record
void Aura_schools_delete() {
    int id;
    cout << "\n🗑 --- Delete School --- 🗑\n";
    cout << "Enter Schools ID to delete: ";
    cin >> id;
    for (auto it = schoolss.begin(); it != schoolss.end(); ++it) {
        if (it->id == id) {
            schoolss.erase(it);
            schools_count--;
            Aura_schools_storing();
            cout << "\n✅ [SUCCESS] School deleted successfully!\n";
            return;
        }
    }
    cout << "\n⚠ [ERROR] School with ID " << id << " not found.\n";
}

// Function to search schools by code
void Aura_schools_searchbycode() {
    string code;
    cout << "\n🔍 --- Search School by Code --- 🔍\n";
    cout << "Enter Schools Code: ";
    cin >> code;
    for (const auto& s : schoolss) {
        if (s.schools_code == code) {
            cout << "\n🎓 [RESULT] School Found:\nID: " << s.id << "\nCode: " << s.schools_code << "\nName: " << s.schools_name << "\nAddress: " << s.schools_address << "\nEmail: " << s.schools_email << "\nWebsite: " << s.schools_website << "\n";
            return;
        }
    }
    cout << "\n⚠ [ERROR] School with code " << code << " not found.\n";
}

// Bubble sort by schools code
void Aura_schools_sortbycode() {
    for (size_t i = 0; i < schoolss.size() - 1; i++) {
        for (size_t j = 0; j < schoolss.size() - i - 1; j++) {
            if (schoolss[j].schools_code > schoolss[j + 1].schools_code) {
                swap(schoolss[j], schoolss[j + 1]);
            }
        }
    }
    cout << "\n🔄 [INFO] Schools sorted by code!\n";
    Aura_schools_retrieve();
}

int main() {
    load_from_file();
    int choice;
    while (true) {
        cout << "\n🌟 --- School Management System --- 🌟\n";
        cout << "1️⃣ Create School\n2️⃣ Update School\n3️⃣ Retrieve All Schools\n4️⃣ Delete School\n5️⃣ Search School by Code\n6️⃣ Sort Schools by Code\n7️⃣ Exit\n";
        cout << "📝 Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Aura_schools_create();
                break;
            case 2:
                Aura_schools_update();
                break;
            case 3:
                Aura_schools_retrieve();
                break;
            case 4:
                Aura_schools_delete();
                break;
            case 5:
                Aura_schools_searchbycode();
                break;
            case 6:
                Aura_schools_sortbycode();
                break;
            case 7:
                cout << "\n👋 [EXIT] Thank you for using the School Management System. Goodbye!\n";
                return 0;
            default:
                cout << "\n⚠ [ERROR] Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
