#include "menutools.h"

namespace menu
{
    namespace
    {
        bool inMenu = false;
        int selectedFiducial = 1;
        
        /**
         * This function internally sets up the menu
         */
        void setupMenu() {
            inMenu = true;
            // clear and print to the screen
            Controller.Screen.clearScreen();
            Controller.Screen.setCursor(1,1);
            Controller.Screen.print("Select a fiducial:");
            Controller.Screen.setCursor(2,1);
            Controller.Screen.print(selectedFiducial);
            Controller.Screen.setCursor(3,1);
            Controller.Screen.print("Select with A");
        }

        /**
         * this internally updates the menu
         */
        void updateMenu() {
            Controller.Screen.setCursor(2,1);
            Controller.Screen.print(selectedFiducial);
            Controller.Screen.setCursor(3,1);
        }
    }

    /**
     * Returns if the controller is in the menu right now.
     */
    bool getMenuStatus()
    {
        return inMenu;
    }

    /**
     * Enters the menu.
     */
    void enterMenu()
    {
        inMenu = true;
        setupMenu();
    }

    /**
     * Exits the menu.
     */
    void exitMenu()
    {
        inMenu = false;
        Controller.Screen.clearScreen();
    }

    /**
     * Moves the menu right
     */
    void moveMenuRight() {
        if (inMenu)
        {
            if (selectedFiducial < 9) {
                ++selectedFiducial;
                updateMenu();
            }
        }
    }
    
    /**
     * Moves the menu left
     */
    void moveMenuLeft() {
        if (inMenu)
        {
            if (selectedFiducial > 1) {
                --selectedFiducial;
                updateMenu();
            }
        }
    }

    int getSelection()
    {
        return selectedFiducial;
    }
}