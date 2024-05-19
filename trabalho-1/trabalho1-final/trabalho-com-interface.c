#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define PI 3.14156295

#define MENU_GRAU_COSSENO 1
#define MENU_GRAU_SENO 2
#define MENU_GRAU_TAN 3
#define MENU_SAIR 7

#define MENU_RAD_COSSENO 8
#define MENU_RAD_SENO 9
#define MENU_RAD_TAN 10

#define MENU_RADPI_COSSENO 11
#define MENU_RADPI_SENO 12
#define MENU_RADPI_TAN 13

#define MENU_ARCO_SENO 4
#define MENU_ARCO_COSSENO 5
#define MENU_ARCO_TAN 6

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void CreateChildWindow(HWND, int type);

//escopo global
HMENU hMenu; 
HWND hEdit, hValueLabel; 
int calculationType; 

//API do Windows
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
    {
        return -1;
    }

    wc.lpszClassName = L"myChildWindowClass";
    wc.lpfnWndProc = ChildWindowProcedure;

    if (!RegisterClassW(&wc))
    {
        return -1;
    }

    CreateWindowW(L"myWindowClass", L"Calculadora Trigonometrica", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) // replace NULL by 0 otherwise Warning
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (wp)
        {
        case MENU_GRAU_COSSENO:
        case MENU_GRAU_SENO:
        case MENU_GRAU_TAN:
        case MENU_ARCO_SENO:
        case MENU_ARCO_COSSENO:
        case MENU_ARCO_TAN:
        case MENU_RAD_COSSENO:
        case MENU_RAD_SENO:
        case MENU_RAD_TAN:
        case MENU_RADPI_COSSENO:
        case MENU_RADPI_SENO:
        case MENU_RADPI_TAN:
            CreateChildWindow(hWnd, wp);
            break;
        case MENU_SAIR:
            DestroyWindow(hWnd);
            break;
        }
        break;

    case WM_CREATE: //quando a janela eh criada
        AddMenus(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hSair = CreateMenu(); //menu para sair
    HMENU hGrausMenu = CreateMenu(); //menu graus
    HMENU hRadMenu = CreateMenu(); //menu radianos sem pi
    HMENU hRadPiMenu = CreateMenu(); //menu radianos com pi
    HMENU hArcoMenu = CreateMenu(); //menu de arcos

    AppendMenu(hGrausMenu, MF_STRING, MENU_GRAU_COSSENO, "Cosseno em Graus");
    AppendMenu(hGrausMenu, MF_STRING, MENU_GRAU_SENO, "Seno em Graus");
    AppendMenu(hGrausMenu, MF_STRING, MENU_GRAU_TAN, "Tangente em Graus");

    AppendMenu(hRadMenu, MF_STRING, MENU_RAD_COSSENO, "Cosseno em Radianos");
    AppendMenu(hRadMenu, MF_STRING, MENU_RAD_SENO, "Seno em Radianos");
    AppendMenu(hRadMenu, MF_STRING, MENU_RAD_TAN, "Tangente em Radianos");

    AppendMenu(hRadPiMenu, MF_STRING, MENU_RADPI_COSSENO, "Cosseno em Radianos com Pi");
    AppendMenu(hRadPiMenu, MF_STRING, MENU_RADPI_SENO, "Seno em Radianos com Pi");
    AppendMenu(hRadPiMenu, MF_STRING, MENU_RADPI_TAN, "Tangente em Radianos com Pi");

    AppendMenu(hArcoMenu, MF_STRING, MENU_ARCO_SENO, "Arco Seno");
    AppendMenu(hArcoMenu, MF_STRING, MENU_ARCO_COSSENO, "Arco Cosseno");
    AppendMenu(hArcoMenu, MF_STRING, MENU_ARCO_TAN, "Arco Tangente");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hGrausMenu, "Entrada Graus");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hRadMenu, "Entrada Radianos");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hRadPiMenu, "Entrada Radianos com Pi");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hArcoMenu, "Arcos");
    AppendMenu(hMenu, MF_STRING, MENU_SAIR, "Sair");

    SetMenu(hWnd, hMenu);
}

void CreateChildWindow(HWND hWnd, int type)
{
    calculationType = type;
    LPCWSTR windowTitle;
    LPCWSTR inputLabel;

    switch (type)
    {
    case MENU_GRAU_COSSENO:
        windowTitle = L"Cosseno em graus";
        inputLabel = L"Entre com o angulo em graus:";
        break;
    case MENU_GRAU_SENO:
        windowTitle = L"Seno em graus";
        inputLabel = L"Entre com o angulo em graus:";
        break;
    case MENU_GRAU_TAN:
        windowTitle = L"Tangente em graus";
        inputLabel = L"Entre com o angulo em graus:";
        break;
    case MENU_ARCO_SENO:
        windowTitle = L"Arco Seno";
        inputLabel = L"Entre com o seno:";
        break;
    case MENU_ARCO_COSSENO:
        windowTitle = L"Arco Cosseno";
        inputLabel = L"Entre com o cosseno:";
        break;
    case MENU_ARCO_TAN:
        windowTitle = L"Arco Tangente";
        inputLabel = L"Entre com a tangente:";
        break;
    case MENU_RAD_COSSENO:
        windowTitle = L"Cosseno em radianos";
        inputLabel = L"Entre com o angulo em radianos:";
        break;
    case MENU_RAD_SENO:
        windowTitle = L"Seno em radianos";
        inputLabel = L"Entre com o angulo em radianos:";
        break;
    case MENU_RAD_TAN:
        windowTitle = L"Tangente em radianos";
        inputLabel = L"Entre com o angulo em radianos:";
        break;
    case MENU_RADPI_COSSENO:
        windowTitle = L"Cosseno em radianos com pi";
        inputLabel = L"Entre com o valor que sera multiplicado por pi:";
        break;
    case MENU_RADPI_SENO:
        windowTitle = L"Seno em radianos com pi";
        inputLabel = L"Entre com o valor que sera multiplicado por pi:";
        break;
    case MENU_RADPI_TAN:
        windowTitle = L"Tangente em radianos com pi";
        inputLabel = L"Entre com o valor que sera multiplicado por pi:";
        break;
    default:
        windowTitle = L"Calculo";
        inputLabel = L"Entre com o valor:";
    }

    HWND hwndChild = CreateWindowW(L"myChildWindowClass", windowTitle, WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU, 150, 150, 300, 200, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", inputLabel, WS_VISIBLE | WS_CHILD, 20, 20, 200, 40, hwndChild, NULL, NULL, NULL);
}

LRESULT CALLBACK ChildWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        hEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 60, 100, 20, hWnd, (HMENU)1, NULL, NULL);
        CreateWindowW(L"Static", L"O valor eh:", WS_VISIBLE | WS_CHILD, 20, 110, 150, 20, hWnd, NULL, NULL, NULL);
        hValueLabel = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD, 20, 140, 150, 20, hWnd, NULL, NULL, NULL);
        break;

    case WM_COMMAND:
        if (HIWORD(wp) == EN_CHANGE && LOWORD(wp) == 1)
        {
            char buffer[256];
            GetWindowText(hEdit, buffer, 256);
            double inputValor = atof(buffer);
            double result;
            bool indefinido = false;

            switch (calculationType)
            {
            case MENU_GRAU_COSSENO:
                result = cos(inputValor * (PI / 180.0));
                break;
            case MENU_GRAU_SENO:
                result = sin(inputValor * (PI / 180.0));
                break;
            case MENU_GRAU_TAN:
                result = tan(inputValor * (PI / 180.0));
                if (tan(inputValor * (PI / 180.0)) > 5730 || tan(inputValor * (PI / 180.0)) < -5730) {
                    indefinido = true;
                }
                break;
            case MENU_ARCO_SENO:
                if (inputValor < -1.0 || inputValor > 1.0) {
                    indefinido = true;
                } else {
                    result = asin(inputValor) * (180.0 / PI);
                }
                break;
            case MENU_ARCO_COSSENO:
                if (inputValor < -1.0 || inputValor > 1.0) {
                    indefinido = true;
                } else {
                    result = acos(inputValor) * (180.0 / PI);
                }
                break;
            case MENU_ARCO_TAN:
                result = atan(inputValor) * (180.0 / PI);
                break;
            case MENU_RAD_COSSENO:
                result = cos(inputValor);
                break;
            case MENU_RAD_SENO:
                result = sin(inputValor);
                break;
            case MENU_RAD_TAN:
                result = tan(inputValor);
                if (tan(inputValor) > 5730 || tan(inputValor) < -5730) {
                    indefinido = true;
                }
                break;
            case MENU_RADPI_COSSENO:
                result = cos(inputValor * PI);
                break;
            case MENU_RADPI_SENO:
                result = sin(inputValor * PI);
                break;
            case MENU_RADPI_TAN:
                result = tan(inputValor * PI);
                if (tan(inputValor * PI) > 5730 || tan(inputValor * PI) < -5730) {
                    indefinido = true;
                }
                break;
            default:
                result = 0.0;
            }

            if (indefinido) {
                strcpy(buffer, "Indefinido");
            } else {
                sprintf(buffer, "%.2f", result);
            }

            SetWindowText(hValueLabel, buffer);
        }
        break;

    case WM_DESTROY:
        DestroyWindow(hWnd);
        break;

    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    
}