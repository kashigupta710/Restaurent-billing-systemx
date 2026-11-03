#include <stdio.h>
#include <string.h>

// =====================================
// FOOD MENU
// =====================================

char foodNames[10][30] = {
    "Paneer Butter Masala",
    "Veg Biryani",
    "Dal Makhani",
    "Butter Naan",
    "Burger",
    "Pizza",
    "French Fries",
    "Cold Drink",
    "Fresh Juice",
    "Coffee"
};

int foodPrices[10] = {
    220, 180, 160, 40,
    100, 250, 90,
    50, 80, 70
};

// =====================================
// GLOBAL VARIABLES
// =====================================

char customerName[50];
char mobileNumber[15];

int tableNumber;
int registered = 0;

int quantities[10] = {0};

int billGenerated = 0;

// Order history
int historyBillNo[50];
char historyName[50][50];
float historyTotal[50];

int historyCount = 0;
int nextBillNo = 1001;


// =====================================
// FUNCTION DECLARATIONS
// =====================================

void displayMenu();
void registerCustomer();
void placeOrder();
void modifyOrder();
void generateBill();
void viewOrderHistory();

float calculateSubtotal();
int hasOrder();


// =====================================
// DISPLAY FOOD MENU
// =====================================

void displayMenu()
{
    int i;

    printf("\n========================================");
    printf("\n             FOOD MENU");
    printf("\n========================================");

    printf("\n\n          MAIN COURSE");
    printf("\n----------------------------------------");

    for(i = 0; i < 4; i++)
    {
        printf("\n%d. %-25s Rs.%d",
               i + 1, foodNames[i], foodPrices[i]);
    }

    printf("\n\n           FAST FOOD");
    printf("\n----------------------------------------");

    for(i = 4; i < 7; i++)
    {
        printf("\n%d. %-25s Rs.%d",
               i + 1, foodNames[i], foodPrices[i]);
    }

    printf("\n\n           BEVERAGES");
    printf("\n----------------------------------------");

    for(i = 7; i < 10; i++)
    {
        printf("\n%d. %-25s Rs.%d",
               i + 1, foodNames[i], foodPrices[i]);
    }

    printf("\n========================================\n");
}


// =====================================
// CHECK WHETHER ORDER EXISTS
// =====================================

int hasOrder()
{
    int i;

    for(i = 0; i < 10; i++)
    {
        if(quantities[i] > 0)
        {
            return 1;
        }
    }

    return 0;
}


// =====================================
// CUSTOMER REGISTRATION
// =====================================

void registerCustomer()
{
    int i;

    if(registered == 1 && hasOrder() == 1
       && billGenerated == 0)
    {
        printf("\nPlease generate the current bill first!");
        return;
    }

    printf("\n========================================");
    printf("\n         CUSTOMER REGISTRATION");
    printf("\n========================================");

    printf("\nEnter Customer Name: ");
    scanf(" %49[^\n]", customerName);

    printf("Enter Mobile Number: ");
    scanf("%14s", mobileNumber);

    printf("Enter Table Number (1-20): ");
    scanf("%d", &tableNumber);

    if(tableNumber >= 1 && tableNumber <= 20)
    {
        registered = 1;
        billGenerated = 0;

        for(i = 0; i < 10; i++)
        {
            quantities[i] = 0;
        }

        printf("\nRegistration Successful!");
        printf("\nWelcome, %s!", customerName);
        printf("\nTable Number: %d", tableNumber);
    }
    else
    {
        printf("\nInvalid Table Number!");
    }

    printf("\n========================================\n");
}


// =====================================
// PLACE FOOD ORDER
// =====================================

void placeOrder()
{
    int item, quantity;
    char more;

    if(registered == 0)
    {
        printf("\nPlease register the customer first!");
        return;
    }

    if(billGenerated == 1)
    {
        printf("\nBill already generated. Register a new customer.");
        return;
    }

    do
    {
        displayMenu();

        printf("\nEnter Food Item Number (1-10): ");
        scanf("%d", &item);

        if(item >= 1 && item <= 10)
        {
            printf("Enter Quantity: ");
            scanf("%d", &quantity);

            if(quantity > 0)
            {
                quantities[item - 1] += quantity;

                printf("\nItem Added Successfully!");
                printf("\nFood: %s", foodNames[item - 1]);
                printf("\nQuantity: %d", quantity);
            }
            else
            {
                printf("\nInvalid Quantity!");
            }
        }
        else
        {
            printf("\nInvalid Food Item Number!");
        }

        printf("\n\nDo you want to order more items? (Y/N): ");
        scanf(" %c", &more);

    } while(more == 'Y' || more == 'y');

    if(hasOrder() == 1)
    {
        printf("\nOrder Placed Successfully!");
    }

    printf("\n");
}


// =====================================
// MODIFY FOOD ORDER
// =====================================

void modifyOrder()
{
    int item, quantity, choice;

    if(registered == 0)
    {
        printf("\nPlease register the customer first!");
        return;
    }

    if(billGenerated == 1)
    {
        printf("\nBill already generated. Modification not allowed.");
        return;
    }

    if(hasOrder() == 0)
    {
        printf("\nNo items have been ordered yet!");
        return;
    }

    displayMenu();

    printf("\nEnter item number to modify (1-10): ");
    scanf("%d", &item);

    if(item < 1 || item > 10)
    {
        printf("\nInvalid Item Number!");
        return;
    }

    printf("\nCurrent Quantity: %d", quantities[item - 1]);

    printf("\n\n1. Add Quantity");
    printf("\n2. Reduce Quantity");
    printf("\n3. Set New Quantity");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("\nEnter Quantity: ");
    scanf("%d", &quantity);

    if(quantity < 0)
    {
        printf("\nInvalid Quantity!");
        return;
    }

    switch(choice)
    {
        case 1:
            if(quantity > 0)
            {
                quantities[item - 1] += quantity;
                printf("\nQuantity Added Successfully!");
            }
            else
            {
                printf("\nQuantity must be greater than zero!");
            }
            break;

        case 2:
            if(quantity <= quantities[item - 1])
            {
                quantities[item - 1] -= quantity;
                printf("\nQuantity Reduced Successfully!");
            }
            else
            {
                printf("\nCannot reduce more than ordered quantity!");
            }
            break;

        case 3:
            quantities[item - 1] = quantity;
            printf("\nQuantity Updated Successfully!");
            break;

        default:
            printf("\nInvalid Choice!");
    }
}


// =====================================
// CALCULATE SUBTOTAL
// =====================================

float calculateSubtotal()
{
    int i;
    float subtotal = 0;

    for(i = 0; i < 10; i++)
    {
        subtotal += quantities[i] * foodPrices[i];
    }

    return subtotal;
}


// =====================================
// GENERATE BILL
// =====================================

void generateBill()
{
    int i;

    float subtotal;
    float discount = 0;
    float gst;
    float finalAmount;
    float discountedAmount;

    if(registered == 0)
    {
        printf("\nPlease register the customer first!");
        return;
    }

    if(billGenerated == 1)
    {
        printf("\nBill has already been generated!");
        return;
    }

    if(hasOrder() == 0)
    {
        printf("\nNo items ordered. Cannot generate bill!");
        return;
    }

    subtotal = calculateSubtotal();

    // Discount calculation

    if(subtotal >= 1000)
    {
        discount = subtotal * 0.10;
    }
    else if(subtotal >= 500)
    {
        discount = subtotal * 0.05;
    }

    discountedAmount = subtotal - discount;

    // Sample GST calculation

    gst = discountedAmount * 0.05;

    finalAmount = discountedAmount + gst;

    // Display receipt

    printf("\n\n========================================");
    printf("\n             THE FOOD CORNER");
    printf("\n           CUSTOMER RECEIPT");
    printf("\n========================================");

    printf("\nBill Number: %d", nextBillNo);
    printf("\nCustomer: %s", customerName);
    printf("\nMobile: %s", mobileNumber);
    printf("\nTable Number: %d", tableNumber);

    printf("\n----------------------------------------");
    printf("\nItem                 Qty       Amount");
    printf("\n----------------------------------------");

    for(i = 0; i < 10; i++)
    {
        if(quantities[i] > 0)
        {
            printf("\n%-20s %3d Rs.%7.2f",
                   foodNames[i],
                   quantities[i],
                   (float)(quantities[i] * foodPrices[i]));
        }
    }

    printf("\n----------------------------------------");

    printf("\nSubtotal:              Rs. %.2f", subtotal);
    printf("\nDiscount:              Rs. %.2f", discount);
    printf("\nGST (5%%):              Rs. %.2f", gst);

    printf("\n----------------------------------------");

    printf("\nFINAL AMOUNT:          Rs. %.2f", finalAmount);

    printf("\n========================================");
    printf("\n       THANK YOU! VISIT AGAIN!");
    printf("\n========================================\n");

    // Save order in history

    if(historyCount < 50)
    {
        historyBillNo[historyCount] = nextBillNo;

        strcpy(historyName[historyCount], customerName);

        historyTotal[historyCount] = finalAmount;

        historyCount++;
    }
    else
    {
        printf("\nOrder History is Full!");
    }

    billGenerated = 1;
    nextBillNo++;
}


// =====================================
// VIEW ORDER HISTORY
// =====================================

void viewOrderHistory()
{
    int i;

    printf("\n========================================");
    printf("\n             ORDER HISTORY");
    printf("\n========================================");

    if(historyCount == 0)
    {
        printf("\nNo Previous Orders Found!");
        return;
    }

    printf("\nBill No.       Customer Name       Amount");
    printf("\n----------------------------------------");

    for(i = 0; i < historyCount; i++)
    {
        printf("\n%-14d %-20s Rs.%.2f",
               historyBillNo[i],
               historyName[i],
               historyTotal[i]);
    }

    printf("\n========================================\n");
}


// =====================================
// MAIN FUNCTION
// =====================================

int main()
{
    int choice;

    do
    {
        printf("\n\n========================================");
        printf("\n          THE FOOD CORNER");
        printf("\n       RESTAURANT BILLING SYSTEM");
        printf("\n========================================");

        printf("\n\n1. Register Customer");
        printf("\n2. Display Food Menu");
        printf("\n3. Place Order");
        printf("\n4. Modify Order");
        printf("\n5. Generate Bill");
        printf("\n6. View Order History");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                registerCustomer();
                break;

            case 2:
                displayMenu();
                break;

            case 3:
                placeOrder();
                break;

            case 4:
                modifyOrder();
                break;

            case 5:
                generateBill();
                break;

            case 6:
                viewOrderHistory();
                break;

            case 7:
                printf("\nThank you for visiting The Food Corner!");
                printf("\nHave a great day!\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.");
        }

    } while(choice != 7);

    return 0;
}