# 🍽️ The Food Corner – Restaurant Billing System

A menu-driven **Restaurant Billing System** developed using the C programming language. This project is designed for first-year computer science students to understand the practical implementation of fundamental C programming concepts.

## 📌 Project Overview

The Food Corner is a terminal-based restaurant billing application that allows restaurant staff to register customers, display food menus, place and modify orders, calculate bills automatically, and maintain order history.

The system simplifies basic restaurant operations through a simple and interactive menu-driven interface.

## ✨ Features

- **Customer Registration:** Register customers with their name, mobile number, and table number.
- **Food Menu Display:** Display food items categorized into Main Course, Fast Food, and Beverages.
- **Place Order:** Select food items and specify quantities.
- **Modify Order:** Add, reduce, or update food quantities.
- **Automatic Bill Generation:** Calculate the total amount based on ordered items.
- **Discount System:**
  - 5% discount on bills of ₹500 or more.
  - 10% discount on bills of ₹1000 or more.
- **GST Calculation:** Automatically calculate 5% GST on the discounted amount.
- **Unique Bill Number:** Generate a unique bill number for every completed transaction.
- **Order History:** Maintain a record of previous bills and customer names.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Code Editor:** Visual Studio Code
- **Libraries:**
  - `stdio.h`
  - `string.h`

## 📚 C Concepts Implemented

This project demonstrates the practical use of:

- Variables and Data Types
- Conditional Statements (`if-else`)
- Switch Case
- Loops (`for`, `do-while`)
- Arrays and 2D Arrays
- Strings and String Functions
- User-Defined Functions
- Global Variables
- Basic Mathematical Operations

## 📂 Project Structure

```text
Restaurant-Billing-System/
│
├── restaurant.c
└── README.md
```

## ▶️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/Restaurant-Billing-System.git
```

### Step 2: Open the Project Folder

```bash
cd Restaurant-Billing-System
```

### Step 3: Compile the Program

Using GCC:

```bash
gcc restaurant.c -o restaurant
```

### Step 4: Run the Program

**Windows:**
```bash
restaurant.exe
```

**Linux / macOS:**
```bash
./restaurant
```

## 🖥️ Main Menu

```text
========================================
          THE FOOD CORNER
       RESTAURANT BILLING SYSTEM
========================================

1. Register Customer
2. Display Food Menu
3. Place Order
4. Modify Order
5. Generate Bill
6. View Order History
7. Exit

Enter your choice:
```

## 🧾 Sample Billing Features

The billing system automatically calculates:

1. Subtotal
2. Applicable Discount
3. GST (5%)
4. Final Amount

**Billing Formula:**

```text
Discounted Amount = Subtotal - Discount

GST = Discounted Amount × 5%

Final Amount = Discounted Amount + GST
```

## 🎯 Project Objective

The main objective of this project is to develop a basic restaurant management application while strengthening fundamental programming skills in C.

It demonstrates how programming concepts can be applied to solve real-world problems through a practical application.

## 🚀 Future Improvements

Some features that can be added in future versions:

- Customer order cancellation.
- Mobile number validation.
- Table availability management.
- Date and time in receipts.
- Saving order history permanently using file handling.
- Admin login system.

## 👨‍💻 Author

**Vedang Dwivedi**

First-Year Student | C Programming Project

## 📜 License

This project is created for educational purposes. Feel free to explore, learn, and improve it.

---

⭐ If you find this project useful, consider giving this repository a star!
