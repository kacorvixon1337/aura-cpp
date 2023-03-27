/*
 * Copyright 2021 AFYaan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License atv
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma comment(lib, "ws2_32")
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include "includes.h"
#include "auth.hpp"
#include <string>
#include "utils.hpp"
#include "skStr.h";
//#include "xorstr.hpp"
//#include "lazy_importer.hpp
#include "antidebug.h"
#include <VirtualizerSDK.h>
#include "xorstr.hpp"
#include "lazy_importer.hpp"
#include "scan.h"
#include "foncik.h"
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);
using namespace std;
using namespace KeyAuth;
std::string name = xorstr_("chuj"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = xorstr_("tquJrrGKlI"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = xorstr_("9e7288e888d427fd15596a11674be5335f50b14051aaf54d6bea064d885c8689"); // app secret, the blurred text on licenses tab and other tabs
std::string version = xorstr_("1.0"); // leave alone unless you've changed version on website
std::string url = xorstr_("https://keyauth.win/api/1.2/"); // change if you're self-hosting
api KeyAuthApp(name, ownerid, secret, version, url);

void listagraczyihuj() {
    jclass bpPlayer = env_->FindClass("pl/afyaan/module/impl/BpPlayer");
    jfieldID bpPlayers = env_->GetStaticFieldID(bpPlayer, "bpPlayers", "Ljava/util/List;");
    jobject players = env_->GetStaticObjectField(bpPlayer, bpPlayers);

    jclass listClass = env_->FindClass("java/util/ArrayList");
    jmethodID listSize = env_->GetMethodID(listClass, "size", "()I");
    jmethodID listGet = env_->GetMethodID(listClass, "get", "(I)Ljava/lang/Object;");
    playersSize = env_->CallIntMethod(players, listSize);

    items.clear();
    for (int i = 0; i < playersSize; i++) {
        jobject player = env_->CallObjectMethod(players, listGet, i);

        jfieldID userNameField = env_->GetFieldID(bpPlayer, "userName", "Ljava/lang/String;");
        userNameGet = env_->GetMethodID(bpPlayer, "getUserName", "()Ljava/lang/String;");
        jmethodID xGet = env_->GetMethodID(bpPlayer, "getX", "()D");
   
        jmethodID yGet = env_->GetMethodID(bpPlayer, "getY", "()D");
        jmethodID zGet = env_->GetMethodID(bpPlayer, "getZ", "()D");
        userNamegraczza = (jstring)env_->CallObjectMethod(player, userNameGet);
        int x = env_->CallDoubleMethod(player, xGet);
        int y = env_->CallDoubleMethod(player, yGet);
        int z = env_->CallDoubleMethod(player, zGet);
        string xfixed = to_string(x);
        string yfixed = to_string(y);
        string zfixed = to_string(z);
        string nickxddd = env_->GetStringUTFChars(userNamegraczza, 0);
        int dlugoscnicku = nickxddd.length();
        if (dlugoscnicku >= 3) {
            ImGui::Text(env_->GetStringUTFChars(userNamegraczza, 0));
            ImGui::SameLine();
            ImGui::Text("|");
            ImGui::SameLine();

            ImGui::Text("X:");

            ImGui::SameLine();

            ImGui::Text(xfixed.c_str());

            ImGui::SameLine();

            ImGui::Text("Y:");

            ImGui::SameLine();

            ImGui::Text(yfixed.c_str());

            ImGui::SameLine();

            ImGui::Text("Z:");

            ImGui::SameLine();

            ImGui::Text(zfixed.c_str());
        }
        BpPlayer newPlayer;
        newPlayer.userName = userNamegraczza;
        newPlayer.x = x;
        newPlayer.y = y;
        newPlayer.z = z;
        items.push_back(newPlayer);
    }
}
bool player_getter(void* data, int index, const char** output)
{
    BpPlayer player = items[index];


    *output = env_->GetStringUTFChars(player.userName, nullptr);
    return true;
}
DWORD rainbow(string ret) {

    static float x = 0, y = 0;
    static float r = 0, g = 0, b = 0;

    for (int i = 0; i < 255; i++) {
        if (i == 255) {
            r, g, b = 0;
        }
        r, g, b + i;
    }


    if (ret == "r") {
        return r;
    }
    else if (ret == "g") {
        return g;
    }
    else if (ret == "b") {
        return b;
    }
}
static float color10[3] = { 1.0 };
int (WINAPI* pSend)(SOCKET s, const char* buf, int len, int flags) = send;
int WINAPI MySend(SOCKET s, const char* buf, int len, int flags);
int __stdcall  MySend(SOCKET s, const char* buf, int len, int flags) {
    return  cheats::blink ? 0 : pSend(s, buf, len, flags);
}


void render(_In_ HDC hDc)
{
    window = WindowFromDC(hDc);
    HGLRC oContext = wglGetCurrentContext();

    if (!done)
    {

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        ImFontConfig m_config;
        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
        ImFontConfig icons_config;
        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;
        m_config.OversampleH = m_config.OversampleV = 3;
        m_config.PixelSnapH = false;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;
        io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

        io.Fonts->AddFontFromMemoryCompressedTTF(minecraftfont_data, minecraftfont, 16);
        ImGui::GetStyle().WindowRounding = 5.0f;// <- Set this on init or use ImGui::PushStyleVar()
        ImGui::GetStyle().WindowBorderSize = 0.f;// <- Set this on init or use ImGui::PushStyleVar()
        ImGui::GetStyle().ChildRounding = 4.0f;// <- Set this on init or use ImGui::PushStyleVar()
        ImGui::GetStyle().WindowPadding = ImVec2(0, 1);

        io.Fonts->AddFontDefault();
        ImGui_ImplWin32_Init(window);
        ImGui_ImplOpenGL2_Init();

        ImGuiStyle* style = &ImGui::GetStyle();
        ImVec4* colors = style->Colors;



        colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        colors[ImGuiCol_WindowBg] = ImVec4(0.01, 0.01, 0.01, 0.5f);
        colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.94f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        colors[ImGuiCol_Border] = ImVec4(0.980, 0.372, 0.626, 1.f);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.54f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.10f, 0.10f, 0.10f, 0.40f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.10f, 0.10f, 0.10f, 0.67f);
        colors[ImGuiCol_TitleBg] = ImVec4(0.280, 0.274, 0.274, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.280, 0.274, 0.274, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.280, 0.274, 0.274, 0.51f);
        colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
        colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_SliderGrab] = ImVec4(0.130, 0.127, 0.127, 1.f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(0.370, 0.370, 0.370, 0.8f);
        colors[ImGuiCol_Button] = ImVec4(0.210, 0.212, 0.212, 1.f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.150, 0.150, 0.150, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.180, 0.180, 0.180, 1.00f);
        colors[ImGuiCol_Header] = ImVec4(0.280, 0.274, 0.274, 0.31f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.280, 0.274, 0.274, 0.80f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.280, 0.274, 0.274, 1.00f);
        colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
        colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
        colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
        colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
        colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
        done = true;
    }

    if (!o_wndproc)  o_wndproc = (WndProc_t)SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    ImGui::GetIO().WantCaptureMouse = cheats::showmenu;
    ImGui::GetIO().MouseDrawCursor = cheats::showmenu;
 
const char* tabs[] = {
"player",
"combat",
"render",
"other",
"unsafe",

};
if (cheats::showmenu) {
    ImGui::SetNextWindowSize(ImVec2(700, 350));
    ImGui::Begin("##blazingtool", &cheats::showmenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    ImGui::SetColorEditOptions(ImGuiColorEditFlags_RGB | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs);
    auto wPos = ImGui::GetWindowPos();
    auto wSize = ImGui::GetWindowSize();
    ImGui::GetForegroundDrawList()->AddRectFilled({ wPos.x + 1, wPos.y }, { wPos.x + wSize.x - 1, wPos.y + 20 }, IM_COL32(46, 46, 46, 255), 5);
    ImGui::GetForegroundDrawList()->AddRectFilled({ wPos.x + 1, wPos.y + 15 }, { wPos.x + wSize.x - 1, wPos.y + 35 }, IM_COL32(46, 46, 46, 255), 0);
    ImGui::GetForegroundDrawList()->AddText(ImVec2(wPos.x + wSize.x / 2 - ImGui::CalcTextSize("BlazingTool").x * 0.5, wPos.y + 10), IM_COL32(255, 255, 255, 255), "BlazingTool");
    ImGui::GetForegroundDrawList()->AddRect(wPos, { wPos.x + wSize.x, wPos.y + wSize.y }, IM_COL32(255, 110, 177, 255), 5);
    ImGui::GetForegroundDrawList()->AddRect({ wPos.x - (float)0.5 , wPos.y - (float)0.5 }, { wPos.x + wSize.x + (float)0.5, wPos.y + wSize.y + (float)0.5 }, IM_COL32(255, 110, 177, 255), 5);
    ImGui::SetCursorPosY(100);
    ImGui::SetCursorPosX(20);
    ImGui::BeginChild("##TABS", ImVec2(170, 200), false, ImGuiWindowFlags_NoBackground);
    for (int i = 0; i < ARRAYSIZE(tabs); i++)
    {
        ImGui::PushStyleColor(ImGuiCol_Text, tab == i ? active : inactive);

        if (ImGui::Button(tabs[i], ImVec2(160, 25)))
            tab = i;
        ImGui::PopStyleColor();
    }


    ImGui::EndChild();
    ImGui::SetCursorPosX(260);
    ImGui::SetCursorPosY(70);
    if (tab == 0) {
        ImGui::BeginChild("##player", ImVec2(400, 200), false, ImGuiWindowFlags_NoBackground);
        ImGui::SetCursorPosY(1);
        ImGui::SetCursorPosX(1);
        ImGui::newcheckbox("Fly", &cheats::fly); ImGui::SameLine(0, 5); ImGui::Bind("##fly bind", &binds::flybind, ImVec2(45, 25));
        ImGui::newcheckbox("blink", &cheats::blink); ImGui::SameLine(0, 5); ImGui::Bind("##blink bind", &binds::blinkbind, ImVec2(45, 25));
        ImGui::newcheckbox("Vclip (down)", &cheats::vclip); ImGui::SameLine(0, 5); ImGui::Bind("##vclip bind", &binds::vclipbind, ImVec2(45, 25));
        ImGui::SliderInt("vclip y", &cheats::vclipsize, 0.0, 20.0, "%f");


        ImGui::EndChild();
    }

    if (tab == 1) {
        ImGui::BeginChild("##combat", ImVec2(400, 200), false, ImGuiWindowFlags_NoBackground);
        ImGui::SetCursorPosY(1);
        ImGui::SetCursorPosX(1);
        ImGui::newcheckbox("killaura", &cheats::killaura); ImGui::SameLine();  ImGui::Bind("##killaura bind", &binds::killaurabind);
        ImGui::SliderInt("reach aura", &cheats::reach, 0, 6, "%f");


        ImGui::EndChild();
    }
    if (tab == 2) {
        ImGui::BeginChild("##render", ImVec2(400, 200), false, ImGuiWindowFlags_NoBackground);
        ImGui::SetCursorPosY(1);
        ImGui::SetCursorPosX(1);
        ImGui::newcheckbox("boxy 3d", &cheats::boxes);
        ImGui::SameLine(0, 15);
        ImGui::newcheckbox("xray", &cheats::xray); ImGui::SameLine();  ImGui::Bind("##xray bind", &binds::xraybind);;
        ImGui::newcheckbox("Chams", &cheats::chams);
        ImGui::SameLine(0, 15);
        ImGui::newcheckbox("Clear ESP", &cheats::clearesp); ImGui::SameLine();  ImGui::Bind("##xeee", &binds::clearespbind);
        ImGui::newcheckbox("Tracers", &cheats::tracers);
        ImGui::SameLine(0, 15);
        ImGui::newcheckbox("cavefinder", &cheats::cavefinder); ImGui::SameLine();  ImGui::Bind("##xdfsd bind", &binds::cavefinderbind);
        ImGui::newcheckbox("Chest ESP", &cheats::chestesp);
        ImGui::SameLine(0, 15);
        ImGui::newcheckbox("Player List", &cheats::listapedalow);
        ImGui::newcheckbox("NameTags Scale", &cheats::nametagsy);
        ImGui::SameLine(0, 15);
        ImGui::SliderInt("Scale Value", &cheats::scalename, 1.0, 20.0, "%f");
        if (cheats::boxes) {
            ImGui::Separator();
            ImGui::newcheckbox("rainbow?", &cheats::rainbowesp);
            ImGui::SameLine(0, 15);
            ImGui::ColorEdit4("##boxy 3d color", color10);
            ImGui::newcheckbox("Fill boxy", &cheats::fillboxy);
        }

        ImGui::EndChild();
    }
    if (tab == 3) {
        ImGui::BeginChild("##other", ImVec2(400, 200), false, ImGuiWindowFlags_NoBackground);
        ImGui::SetCursorPosY(1);
        ImGui::SetCursorPosX(1);
        ImGui::Text("Lista: ");
        listagraczyihuj();


        ImGui::EndChild();
    }
    if (tab == 4) {
        ImGui::BeginChild("##unsafe", ImVec2(400, 200), false, ImGuiWindowFlags_NoBackground);



        ImGui::EndChild();
    }
    ImGui::End();

}
if (cheats::listapedalow)
{
    if (cheats::showmenu) {
        ImGui::Begin("Player List", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar);
    }
    else {
        ImGui::Begin("Player List", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
    }

    listagraczyihuj();
    ImGui::End();

}
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    wglMakeCurrent(hDc, oContext);

    if (!cheats::rainbowesp) {
        color10tak = color10[0];
        color20tak = color10[1];
        color30tak = color10[2];
    }
    else {
        color10tak = rainbow("r");
        color20tak = rainbow("g");
        color30tak = rainbow("b");
    }

    jclass test = env_->FindClass("pl/afyaan/module/impl/toggle");
    jclass testxd = env_->FindClass("pl/afyaan/module/impl/movement/Speed");
    if (cheats::killaura)
    {
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "killauraReach", "(D)V"), (double)cheats::reach);
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "killauraOn", "()V"));

    }
    else
    {
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "killauraOff", "()V"));

    }
    if (cheats::speed) {
        //env_->CallStaticVoidMethod(testxd, env_->GetStaticMethodID(env_->FindClass("pl/afyaan/module/impl/movement/Speed"), "onEnable", "()V"));
    }

    if (cheats::fly)
    {
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "flyOn", "()V"));
    }
    else
    {
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "flyOff", "()V"));
    }
    if (cheats::vclip)
    {
        //for (int i = 0; i < 5; i++) {
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setVclip", "(D)V"), (double)cheats::vclipsize);
        env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(env_->FindClass("pl/afyaan/module/impl/movement/Vclip"), "onEnable", "()V"));
        //}
        cheats::vclip = false;
    }
    if (cheats::players) {

    }

 
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "stepSize", "(F)V"), cheats::stepsize);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setMotionX", "(D)V"), (double)cheats::motionXf);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setMotionY", "(D)V"), (double)cheats::motionYf);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setMotionZ", "(D)V"), (double)cheats::motionZf);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setNewX", "(D)V"), (double)cheats::newX);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setNewY", "(D)V"), (double)cheats::newY);
    env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(test, "setNewZ", "(D)V"), (double)cheats::newZ);
    //jclass speedmine = env_->FindClass("pl/afyaan/module/impl/toggle");
    //env_->CallStaticVoidMethod(test, env_->GetStaticMethodID(env_->FindClass("pl/afyaan/module/impl/toggle"), "setSpeedmine", "(F)V"), cheats::speedmine);
}
BOOL __stdcall hkSwapBuffers(_In_ HDC hDc)
{

    if (GetAsyncKeyState(VK_INSERT) & 1)
    {
        cheats::showmenu = !cheats::showmenu;
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 1)
    {
        cheats::showmenu = false;
    }
    if (GetAsyncKeyState(binds::xraybind) & 1) {
        cheats::xray = !cheats::xray;
    }
    if (GetAsyncKeyState(binds::chams) & 1) {
        cheats::chams = !cheats::chams;
    }
    if (GetAsyncKeyState(binds::flybind) & 1) {
        cheats::fly = !cheats::fly;
    }
    if (GetAsyncKeyState(binds::vclipbind) & 1) {
        cheats::vclip = !cheats::vclip;
    }
    if (GetAsyncKeyState(binds::playersbind) & 1) {
        cheats::players = !cheats::players;
    }
    if (GetAsyncKeyState(binds::killaurabind) & 1) {
        cheats::killaura = !cheats::killaura;
    }
    if (GetAsyncKeyState(binds::blinkbind) & 1) {
        cheats::blink = !cheats::blink;
    }
    if (cheats::blink && cheats::blinkhook == "niema") {
        HMODULE WS2 = GetModuleHandle("ws2_32.dll");
        void* send_packet = GetProcAddress(WS2, "WSASend");
        MH_CreateHook(send_packet, MySend, (void**)&pSend);
        MH_EnableHook(send_packet);
        cheats::blinkhook = "jest";
        cout << "BLINK HOOKED " << endl;
    }

    if (GetAsyncKeyState(binds::cavefinderbind) & 1) {
        cheats::cavefinder = !cheats::cavefinder;
    }
    if (GetAsyncKeyState(binds::clearespbind) & 1) {
        cheats::clearesp = !cheats::clearesp;
    }
    if (window != WindowFromDC(hDc)) {
        window = WindowFromDC(hDc);
        if (!window) return oSwapBuffers(hDc);

        o_wndproc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
        //glewInit();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        ImGui_ImplWin32_Init(window);
        ImGui_ImplOpenGL2_Init();
    }
    render(hDc);
    return oSwapBuffers(hDc);
}
BOOL __stdcall hglCallList(GLuint list) {

    if (cheats::xray) {

        glEnable(GL_DEPTH_TEST);
        oglCallList(list);
        glDisable(GL_DEPTH_TEST);
    }
    else {
        glEnable(GL_DEPTH_TEST);
    }

    if (cheats::cavefinder) {
        glDisable(GL_DEPTH_TEST);
    }
    else {
 
        glEnable(GL_DEPTH_TEST);

    }


    if (cheats::chams) {
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_TEXTURE_2D);
        oglCallList(list);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
    }
    else {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
    }
    if (cheats::clearesp) {

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        oglCallList(list);
        glCullFace(GL_FRONT_AND_BACK);

        //
    }
    else {
        glCullFace(GL_BACK);
        glDisable(GL_CULL_FACE);

    }

    return oglCallList(list);
}
void __stdcall hkglScalef(float x, float y, float z)  //nametagi and esp
{
    pniggerv2(x, y, z);    

    if (x == -0.026666669175028801f)
    {
        if (cheats::nametagsy) {
            glScalef(cheats::scalename, cheats::scalename, cheats::scalename);
        }
        else {
            glScalef(1,1,1);
        }
    }
    if (x == 0.9375F and y == 0.9375F and z == 0.9375F)
    {
        if (cheats::boxes) {
            if (cheats::fillboxy) {

            }
            else {
                Radius radius(0.8F, 2.0F, 0.8F);
                glPushAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
                glPushMatrix();

                glDisable(GL_TEXTURE_2D);
                glDisable(GL_CULL_FACE);
                glDisable(GL_LIGHTING);
                glDisable(GL_DEPTH_TEST);


                glTranslatef(0.0F, -1.0F, 0.0F);

                glColor3f(color10tak, color20tak, color30tak);


                glBegin(GL_LINES);
                glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
                glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

                glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
                glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);

                glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
                glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

                glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
                glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

                glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
                glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);

                glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
                glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

                glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
                glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);

                glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
                glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

                glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
                glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);

                glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
                glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

                glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
                glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);

                glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
                glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
                glEnd();



                glPopMatrix();

                glPopAttrib();
                glEnable(GL_DEPTH_TEST);
            }


        }

        if (cheats::tracers || cheats::fillboxy) {
            savePosition(entity, 0.0F, -1.0F, 0.0F);
        }
    }



}


void __stdcall myglTranslatef(float x, float y, float z)
{
    ogltranslatef(x, y, z);

    // chest
    if (cheats::chestesp) {
        if (x == 0.5 and y == 0.4375 and z == 0.9375)
        {
            savePosition(chest, 0.0F, 0.0625F, -0.4375F);
        }

        // large chest
        if (x == 1 and y == 0.4375 and z == 0.9375)
        {
            savePosition(largeChest, 0.0F, 0.0625F, -0.4375F);
        }
    }
}

void __stdcall myglOrtho(double left, double right, double bottom, double top, double zNear, double zFar)
{
    if (zNear == 1000 and zFar == 3000)
    {

        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glPushMatrix();

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_CULL_FACE);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);

        glEnable(GL_LINE_SMOOTH);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        draw(chest, Radius(1.0F, 1.0F, 1.0F));
        draw(largeChest, Radius(2.0F, 1.0F, 1.0F));
        if (cheats::fillboxy) {
            draw(entity, Radius(0.8F, 2.0F, 0.8F));
        }
        if (cheats::tracers) {
            draw_lines(entity, Radius(0.8F, 2.0F, 0.8F));
        }

        glPopAttrib();
        glPopMatrix();
    }

    oglOrtho(left, right, bottom, top, zNear, zFar);
}


int main(int argsLength, const char* args[])
{

    //LI_FN(CreateThread)(nullptr, 0, Thread, nullptr, 0, nullptr);
    std::string consoleTitle = (std::string)skCrypt("blazingtool | you are currently using ") + compilation_date + " " + compilation_time + " build.";
    SetConsoleTitleA(consoleTitle.c_str());
    std::cout << xorstr_("\nwait...");
    system("cls");
    system("color d");
    /*KeyAuthApp.init();
    if (!KeyAuthApp.data.success)
    {
        std::cout << skCrypt("\nbruh: ") << KeyAuthApp.data.message;
        Sleep(1500);
        exit(0);
    }
       std::string username;
    std::string password;
    std::cout << skCrypt("\nusername: ");
    std::cin >> username;
    std::cout << skCrypt("\npassword: ");
    std::cin >> password;
    KeyAuthApp.login(username, password);
   if (!KeyAuthApp.data.success)
    {
        std::cout << skCrypt("\nbruh: ") << KeyAuthApp.data.message;
        Sleep(1500);
        exit(0);
    }
    for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
        auto sub = KeyAuthApp.data.subscriptions.at(i);
        std::cout << skCrypt("\n name: ") << sub.name;
    }
    KeyAuthApp.check();*/
    std::string usernameXD;
    cout << "\nmc username: ";
    cin >> usernameXD;
    std::string uuidxd;
    cout << "\nuuid: ";
    cin >> uuidxd;
    std::string accesstoken;
    cout << "\naccesstoken: ";
    cin >> accesstoken;
    std::string rammm;
    cout << "\ngb ramu : ";
    cin >> rammm;

    LI_FN(LoadLibraryA)(xorstr_("opengl32.dll"));
    MH_Initialize();

    if (HMODULE hMod = GetModuleHandleA("opengl32.dll")) {
        void* ptr = GetProcAddress(hMod, "wglSwapBuffers");
        void* call = GetProcAddress(hMod, "glCallList");
        void* nigger = GetProcAddress(hMod, "glScalef");
        void* gltranslatefptr = GetProcAddress(hMod, "glTranslatef");
        void* glorthoptr = GetProcAddress(hMod, "glOrtho");

        MH_CreateHook(ptr, hkSwapBuffers, reinterpret_cast<void**>(&oSwapBuffers));
        MH_CreateHook(call, hglCallList, reinterpret_cast<void**>(&oglCallList));
        MH_CreateHook(nigger, hkglScalef, reinterpret_cast<void**>(&pniggerv2));
        MH_CreateHook(gltranslatefptr, myglTranslatef, reinterpret_cast<void**>(&ogltranslatef));
        MH_CreateHook(glorthoptr, myglOrtho, reinterpret_cast<void**>(&oglOrtho));
      
    }


    MH_EnableHook(MH_ALL_HOOKS);
    Sleep(1000);
    string dir = GetExeDir();
    string gameDir = dir + string("\\gameDir");
    string assetsDir = gameDir + string("\\assets");
    string jarPath = gameDir + string("\\versions\\blazingpack_1.8.8\\blazingpack_1.8.8.jar");
    string binariesDir = gameDir + string("\\bin\\binaries");
    string libraries = getLibraries(gameDir);

    string optClientJar = string("-Dminecraft.client.jar=") + jarPath;
    string optLibraryPath = string("-Djava.library.path=") + binariesDir;
    string optClassPath(string("-Djava.class.path=") + libraries);
    string mainMethod("pl/blazingpack/launcher/BlazingPackLauncher");
    unique_ptr<Loader> loader(new Loader(jarPath, mainMethod));

    std:string ramkoncowy = "-Xmx" + rammm + "G";
    loader->AddJVMArg(ramkoncowy.c_str());
    loader->AddJVMArg("-Xverify:none");
    loader->AddJVMArg("-XX:+UnlockExperimentalVMOptions");
    loader->AddJVMArg("-XX:+UseG1GC");
    loader->AddJVMArg("-XX:G1NewSizePercent=20");
    loader->AddJVMArg("-XX:G1ReservePercent=20");
    loader->AddJVMArg("-XX:MaxGCPauseMillis=50");
    loader->AddJVMArg("-XX:G1HeapRegionSize=32M");
    loader->AddJVMArg("-Xverify:none");
    loader->AddJVMArg(optLibraryPath.c_str());
    loader->AddJVMArg(optClientJar.c_str());
    loader->AddJVMArg(optClassPath.c_str());
    loader->AddArg("--username");
    loader->AddArg(usernameXD.c_str());
    loader->AddArg("--version");
    loader->AddArg("1.8.8");
    loader->AddArg("--gameDir");
    loader->AddArg(gameDir.c_str());
    loader->AddArg("--assetsDir");
    loader->AddArg(assetsDir.c_str());
    loader->AddArg("--assetIndex");
    loader->AddArg("1.8");
    loader->AddArg("--uuid");
    loader->AddArg(uuidxd.c_str());
    loader->AddArg("--accessToken");
    loader->AddArg(accesstoken.c_str());
    loader->AddArg("--userProperties");
    loader->AddArg("{}");
    loader->AddArg("--userType");
    loader->AddArg("msa");

    loader->SetPassword("dupa");

    loader->RunFromMemory(rawData, sizeof(rawData), args, argsLength);
    jvm_ = loader->jvm;
    env_ = loader->env;
    //KeyAuthApp.check();
    loader->Run(args, argsLength);

}


std::string tm_to_readable_time(tm ctx) {
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
    auto cv = strtol(timestamp.c_str(), NULL, 10); // long

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}