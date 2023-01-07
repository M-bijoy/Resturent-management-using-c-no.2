#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAX_RATE 0.08		// Sales tax rate
#define MAX_ITEMS 100		// Maximum number of menu items

// Structure for a menu item
struct Item
{
  char name[20];		// Name of item
  double price;			// Price of item
};

// Structure for an order item
struct OrderItem
{
  char name[20];		// Name of item
  double price;			// Price of item
};

// Function prototypes
void editMenu (struct Item menu[], int *n);
void addItem (struct Item menu[], int *n);
void deleteItem (struct Item menu[], int *n);
void displayMenu (struct Item menu[], int n);
void placeOrder (struct Item menu[], int n);
void editOrder (struct OrderItem order[], int *n);
void addOrderItem (struct OrderItem order[], int *n, struct Item menu[],
		   int m);
void deleteOrderItem (struct OrderItem order[], int *n);
void displayOrder (struct OrderItem order[], int n);
void printBill (struct OrderItem order[], int n);

int
main (void)
{
  struct Item menu[MAX_ITEMS];	// Menu
  int n = 0;			// Number of menu items
  int choice;			// User's menu choice

  // Loop until the user chooses to quit
  while (1)
    {
      printf ("\nMenu:\n");
      printf ("1. Edit menu\n");
      printf ("2. Place order\n");
      printf ("3. Quit\n");
      printf ("Enter choice: ");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  editMenu (menu, &n);
	  break;
	case 2:
	  placeOrder (menu, n);
	  break;
	case 3:
	  return 0;
	default:
	  printf ("Invalid choice.\n");
	  break;
	}
    }

  return 0;
}

// Function to edit the menu
void
editMenu (struct Item menu[], int *n)
{
  int choice;			// User's menu choice

  // Loop until the user chooses to return to the main menu
  while (1)
    {
      printf ("\nMenu editor:\n");
      printf ("1. Add item\n");
      printf ("2. Delete item\n");
      printf ("3. Display menu\n");
      printf ("4. Return to main menu\n");
      printf ("Enter choice: ");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  addItem (menu, n);
	  break;
	case 2:
	  deleteItem (menu, n);
	  break;
	case 3:
	  displayMenu (menu, *n);
	  break;
	case 4:
	  return;
	default:
	  printf ("Invalid choice.\n");
	  break;
	}
    }
}
