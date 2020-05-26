#include "figure.h"
#include "field.h"
#include "UI.h"

int main()
{
    Field field = Field();
    ManagementInterface gui = ManagementInterface();

    while(true)
    {
        gui.update_draw_field(field);
        gui.control_terminal(field);
    }
    return 0;
}