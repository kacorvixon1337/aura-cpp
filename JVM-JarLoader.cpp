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
#define _CRT_SECURE_NO_WARNINGS

#define WIN32_LEAN_AND_MEAN
void listagraczyihuj();
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
void doSearch() {
    HWND hwnd = FindWindowA(("AAAA"), NULL);
    DWORD procId;
    GetWindowThreadProcessId(hwnd, &procId);
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
    void* addr1 = ScanEx("\xC7\x42\x14\x05", "xxxx", (char*)0x1000000, 0x9000000, handle);
    cout << addr1;
    WriteProcessMemory(handle, addr1, "\x90\x90\x90\x90\x90\x90\x90", 7, NULL);
    cheats::speedmine = false;
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

        io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 17.f, &CustomFont);
        io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 17.0f, &icons_config, icons_ranges);


        io.Fonts->AddFontDefault();
        ImGui_ImplWin32_Init(window);
        ImGui_ImplOpenGL2_Init();

        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowMinSize = ImVec2(555, 348);
        style.Colors[ImGuiCol_TitleBg] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_TitleBgActive] = ImColor(35, 35, 35, 255);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(35, 35, 35, 255);
        style.Colors[ImGuiCol_FrameBg] = ImColor(54, 54, 54, 255);
        style.Colors[ImGuiCol_FrameBgActive] = ImColor(72, 76, 77, 255);
        style.Colors[ImGuiCol_FrameBgHovered] = ImColor(72, 76, 77, 255);
        style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
        style.Colors[ImGuiCol_SliderGrab] = ImColor(181, 189, 188, 255);
        style.Colors[ImGuiCol_SliderGrabActive] = ImColor(181, 189, 188, 255);
        style.Colors[ImGuiCol_ButtonActive] = ImColor(23, 23, 23);
        style.Colors[ImGuiCol_ButtonHovered] = ImColor(23, 23, 23);
        style.Colors[ImGuiCol_Button] = ImColor(23, 23, 23);
        style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
        style.Colors[ImGuiCol_WindowBg] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_ChildBg] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_TabActive] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_TabHovered] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_TabUnfocused] = ImColor(28, 28, 39, 255);
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImColor(23, 23, 23, 255);
        style.Colors[ImGuiCol_Tab] = ImColor(23, 23, 23, 255);
        style.WindowRounding = 6;
        style.FrameRounding = 6;
        style.GrabRounding = 6;
        style.TabRounding = 6;
        style.WindowBorderSize = false;
        style.ChildRounding = 6;

        done = true;
    }

    if (!o_wndproc)  o_wndproc = (WndProc_t)SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    ImGui::GetIO().WantCaptureMouse = cheats::showmenu;
    ImGui::GetIO().MouseDrawCursor = cheats::showmenu;

    if (cheats::showmenu)
    {
        ImGui::SetColorEditOptions(ImGuiColorEditFlags_NoInputs);
        ImGui::Begin(xorstr_("##xyz"), 0, ImGuiWindowFlags_NoTitleBar | ImGuiColorEditFlags_NoInputs | ImGuiWindowFlags_NoResize);
        ImGui::BeginChild("##Bar", ImVec2(110, 333), false);
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::SameLine(5);
        ImGui::Text(ICON_FA_FIRE" blazingtool");
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Text, active);
        ImGui::Text(xorstr_("          (vip)"));
        ImGui::Text(xorstr_("__________"));
        ImGui::PopStyleColor();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Separator, inactive);
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Separator, tab == 1 ? active : inactive);
        ImGui::SameLine(5);
        const char* tabs[] = {
            ICON_FA_MALE" Combat",
            ICON_FA_BOLT" Movement",
            ICON_FA_EYE " Visuals",
            ICON_FA_MAP " Players",
        };
        ImGui::BeginGroup();
        for (int i = 0; i < ARRAYSIZE(tabs); i++)
        {
            if (ImGui::Button(tabs[i], ImVec2(100, 34)))
                tab = i;
            ImGui::PushStyleColor(ImGuiCol_Separator, tab == i ? active : inactive);
            ImGui::Separator();
        }
        ImGui::EndGroup();
        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::EndChild();
        if (tab == 0)
        {
            ImGui::SameLine();
            ImGui::BeginChild("##combat", ImVec2(420, 333), false);
            ImGui::newcheckbox("killaura", &cheats::killaura); ImGui::SameLine();  ImGui::Bind("##killaura bind", &binds::killaurabind);
            ImGui::SliderFloat("reach aura", &cheats::reach, 0, 6, "%f");
            ImGui::EndChild();
        }
        if (tab == 1)
        {
            ImGui::SameLine();
            ImGui::BeginChild("##movement", ImVec2(420, 333), false);
            //ImGui::newcheckbox("speed", &cheats::speed);
            //ImGui::newcheckbox("speed", &cheats::speed);

            if (cheats::speed) {
                ImGui::SliderFloat("x", &cheats::motionXf, 0, 5, "%f");
                ImGui::SliderFloat("y", &cheats::motionYf, 0, 5, "%f");
                ImGui::SliderFloat("z", &cheats::motionZf, 0, 5, "%f");
            }
            ImGui::newcheckbox("Fly", &cheats::fly); ImGui::SameLine(0, 5); ImGui::Bind("##fly bind", &binds::flybind, ImVec2(45, 25));
            ImGui::newcheckbox("blink", &cheats::blink); ImGui::SameLine(0, 5); ImGui::Bind("##blink bind", &binds::blinkbind, ImVec2(45, 25));
            ImGui::newcheckbox("Vclip (down)", &cheats::vclip); ImGui::SameLine(0, 5); ImGui::Bind("##vclip bind", &binds::vclipbind, ImVec2(45, 25));
            ImGui::SliderFloat("vclip y", &cheats::vclipsize, 0.0, 20.0, "%f");
            ImGui::newcheckbox("speedmine", &cheats::speedmine);
            //ImGui::SliderFloat("new x", &cheats::newX, 0.0, 20.0, "%f");
            //ImGui::SliderFloat("new y", &cheats::newY, 0.0, 20.0, "%f");
            //ImGui::SliderFloat("new z", &cheats::newZ, 0.0, 20.0, "%f");
            ImGui::EndChild();
        }
        if (tab == 2)
        {
            ImGui::SameLine();
            ImGui::BeginChild("##visssuals", ImVec2(420, 333), false);
            ImGui::newcheckbox("boxy 3d", &cheats::boxes);
            if (cheats::boxes) {
                ImGui::SameLine(0, 130);
                ImGui::ColorEdit4("##boxy 3d color", color10);
                ImGui::newcheckbox("rainbow?", &cheats::rainbowesp);
                ImGui::newcheckbox("Fill boxy", &cheats::fillboxy);
            }

            ImGui::newcheckbox("xray", &cheats::xray); ImGui::SameLine();  ImGui::Bind("##xray bind", &binds::xraybind);
            ImGui::newcheckbox("Chams", &cheats::chams);
            ImGui::newcheckbox("Chest ESP", &cheats::chestesp);
            ImGui::newcheckbox("Tracers", &cheats::tracers);
            ImGui::newcheckbox("cavefinder", &cheats::cavefinder); ImGui::SameLine();  ImGui::Bind("##xdfsd bind", &binds::cavefinderbind);
            ImGui::newcheckbox("Clear ESP", &cheats::clearesp); ImGui::SameLine();  ImGui::Bind("##xeee", &binds::clearespbind);
            ImGui::newcheckbox("Player List", &cheats::listapedalow);
            ImGui::EndChild();
        }
        if (tab == 3) {
            niemawtabie = true;
            ImGui::SameLine();

            ImGui::BeginChild("##listapizd", ImVec2(420, 333), false);
            ImGui::Text("Lista: ");
            listagraczyihuj();
            ImGui::EndChild();
        }
        ImGui::EndChild();
        ImGui::End();
    }

    if (cheats::listapedalow)
    {
        if (cheats::showmenu) {
            ImGui::Begin("Player List", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
        }
        else {
            ImGui::Begin("Player List", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove);
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
    if (cheats::speedmine) {
        doSearch();
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
        glDepthRange(1, 0);
        oglCallList(list);
        glDepthRange(0, 1);
    }

    if (cheats::cavefinder) {
        //glGetFloatv(GL_CURRENT_COLOR, curcolor);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        //glColor4f(curcolor[0], curcolor[1], curcolor[2], 1.0);
    }
    else {
        //glGetFloatv(GL_CURRENT_COLOR, curcolor);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        // glPopMatrix();
        // glColor4f(curcolor[0], curcolor[1], curcolor[2], 1.0);
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


    if (cheats::chams) {
        glEnable(0x8037u);
        glPolygonOffset(2, -2000000.0);
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
    system("color 3");
    KeyAuthApp.init();
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
        //std::cout << skCrypt("\n name: ") << sub.name;
    }
    KeyAuthApp.check();
    std::string usernameXD;
    cout << "\nmc username: ";
    cin >> usernameXD;
    std::string uuidxd;
    cout << "\nuuid: ";
    cin >> uuidxd;
    std::string accesstoken;
    cout << "\naccesstoken: ";
    cin >> accesstoken;
    /**
* opengl hook Xd
*/
//LoadLibraryA("opengl32.dll");
    LI_FN(LoadLibraryA)(xorstr_("opengl32.dll"));
    //LoadLibraryA("ws2_32.dll");
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

        MH_QueueEnableHook(ptr);
        MH_QueueEnableHook(call);
        MH_QueueEnableHook(nigger);
        MH_QueueEnableHook(gltranslatefptr);
        MH_QueueEnableHook(glorthoptr);
    }
    MH_ApplyQueued();
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

    loader->AddJVMArg("-Xmx5G");

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
    KeyAuthApp.check();
    loader->Run(args, argsLength);
}

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