// ==WindhawkMod==
// @id              macos-style-dock
// @name            MacOS Style Dock
// @description     Turns the Windows 11 taskbar into a macOS-style dock with magnifying icons
// @version         1.1
// @author          Zach Vaughn
// @github          https://github.com/zachvdev
// @include         explorer.exe
// @architecture    amd64
// @compilerOptions -lole32 -loleaut32 -lruntimeobject -lversion -lgdi32 -lshell32 -lshcore -ladvapi32
// @license         GPL-3.0
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# MacOS Style Dock

Turns the Windows 11 taskbar into a dock with the look and feel of macOS,
while it keeps working the way Windows does. It restyles the real taskbar
rather than replacing it, so pinned apps, jump lists, thumbnails, dragging
files onto apps and rearranging your apps all work as usual. (Unlike
"Taskbar Dock Animation", which magnifies the stock taskbar's icons, and "Mac
Island & Dock", which replaces the taskbar with a separate dock window.)

![The dock in action](https://i.imgur.com/z2GaRW8.gif)

## The look

- **A frosted glass dock.** Your icons sit on a rounded plate of blurred,
  tinted glass, floating just above the bottom of the screen, in place of the
  taskbar's flat background. It's dark, light, or follows your Windows theme,
  and its edge is either a thin outline or soft inner highlights.
- **Bigger icons, no boxes.** Icons are shown larger, without the square
  highlight Windows draws behind them on hover or for the active app.
- **Sharp at any size.** Icons are loaded at the size they're shown at when
  fully magnified, so they stay crisp as they grow.
- **Running indicators.** A small dot under each running app, just above the
  bottom of the dock: bright for the app you're using, dim for the others.
- **Badges where they belong.** Unread counts and overlay icons sit on the
  top-right corner of their icon and grow with it.
- **Dividers.** Thin lines separate Start, Task View and File Explorer from
  your other apps, and your apps from the Recycle Bin.
- **A tidier system tray.** The clock, notifications and tray icons on the
  right keep a fixed size and position, with even margins from the screen
  edges, whatever size the dock is.

## How it works

- **Magnification.** Icons grow as the pointer passes over them, smoothly
  falling off with distance, and push their neighbors aside. As on a Mac,
  the dock grows from one end: with the pointer right of its middle, its
  left end stays put and its right end moves, and the other way around. The
  dock shrinks back as soon as the pointer leaves it.
- **Over your windows.** Maximized windows reach down to the top of the
  dock, and magnified icons rise over them. Windows still keeps the dock's
  own strip of the screen free.
- **Auto-hide.** Turn on "Auto-hide the dock" and the dock slides away when
  the pointer leaves it and comes back when you move to the bottom edge of
  the screen. Windows then keeps no strip of the screen free for it, so
  windows can go underneath.
- **A fixed order.** Start comes first, then Task View, then File Explorer,
  a divider, and the rest of your apps. Whenever File Explorer is pinned or
  open, it keeps its spot next to the divider and can't be dragged
  elsewhere; your other apps can be rearranged as usual.
- **Menus and previews in the right place.** Right-click menus open above
  the icon you clicked, and hover previews and tooltips sit just above the
  dock, or above the magnified icon.
- **A Recycle Bin** at the right end of the dock, using Windows' own icon,
  which shows whether it's empty or full. Click it to open it, drag files
  onto it to delete them (they can be restored), or right-click it to open
  or empty it.

## Settings

- **Behavior:** auto-hide the dock.
- **Dock Panel:** the size of the icons and dock, the space between icons,
  the gap between the dock and the bottom of the screen, the dock's color
  (System, Dark or Light), its edge style (Outline or Inner highlights),
  tint and blur.
- **Magnification:** how much icons grow, how far from the pointer they
  grow, and how long the animation takes.
- **Dock Items:** the divider after File Explorer, the Recycle Bin, and the
  Start button.
- **System Tray:** hide the system tray (the clock, volume, network and tray
  icons).

## Compatibility

- Windows 11 only, with the taskbar at the bottom of the screen.
- x64 PCs only for now; ARM64 isn't supported yet.
- The "Small taskbar buttons" setting isn't supported.
- Leave Windows' "Automatically hide the taskbar" setting alone. While the
  mod is loaded, it turns that setting on behind the scenes (that's how
  maximized windows can reach the dock) and keeps the taskbar from hiding
  unless "Auto-hide the dock" is on. It puts the setting back as it was when
  the mod is unloaded. If the mod can't put it back, for example when
  Windhawk is uninstalled while Explorer isn't running, turn it off yourself
  in Windows' taskbar settings.
- Icons are loaded at high resolution on Windows 11 with the October 2024
  update (KB5044384) or later. On older builds, magnified icons are blurrier.
- Not designed to be used with other taskbar mods. In particular, it sets
  the taskbar's height and icon size, lays out and animates its icons
  itself, and places their right-click menus, so don't combine it with
  "Taskbar height and icon size", "Taskbar Dock Animation", "Taskbar Dock
  Animation Plus", "Mac Island & Dock", "Taskbar Multirow" or "Start button
  always on the left". "Windows 11 Taskbar Styler" can be used for things
  the dock doesn't change, such as the volume popup, but styling the same
  elements as the dock may conflict with it.
- If Windows' Smart App Control is on, it blocks this mod (as it does all
  Windhawk mods), because the mod is compiled on your PC and isn't signed.

## Credits

The taskbar height code is based on m417z's "Taskbar height and icon size"
mod. The way it handles dragging icons and places right-click menus follows
his "Taskbar Multirow" mod, and the way it keeps the taskbar shown follows
his "Taskbar auto-hide when maximized" mod. The running-indicator dots and
the hiding of the Start button and system tray follow rules from the
"Windows 11 Taskbar Styler" mod (all GPL-3.0).
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- behavior:
  - autoHide: false
    $name: Auto-hide the dock
    $description: Hide the dock when the pointer is away from it, and slide it back when you move to the bottom edge of the screen.
  $name: Behavior
- dock:
  - size: 55
    $name: Size (0-100)
    $description: Size of the icons and the dock. (Default = 55)
  - iconSpacing: 13
    $name: Icon spacing (px)
    $description: Space between each icon in the dock. (Default = 13)
  - bottomGap: 7
    $name: Bottom gap (px)
    $description: Space between the bottom of the screen and the dock. (Default = 7)
  - color: auto
    $name: Color
    $description: The color of the dock panel.
    $options:
    - auto: System
    - dark: Dark
    - light: Light
  - style: outline
    $name: Style
    $description: Outline draws a thin edge around the dock. Inner highlights draws light lines along the top and bottom only, not around the corners.
    $options:
    - outline: Outline
    - highlights: Inner highlights
  - tint: 20
    $name: Tint (0-100)
    $description: How opaque the dock panel is. (Default = 20)
  - blur: 35
    $name: Blur (0-100)
    $description: How blurred the dock panel is. (Default = 35)
  $name: Dock Panel
- magnification:
  - amount: 60
    $name: Amount (0-100)
    $description: How much the icons grow when hovered. (Default = 60)
  - range: 55
    $name: Range (0-100)
    $description: How far from the pointer icons grow. (Default = 55)
  - smoothing: 100
    $name: Smoothing (ms)
    $description: Duration of animation transitions. (Default = 100)
  $name: Magnification
- items:
  - appsDivider: true
    $name: Divider after File Explorer
    $description: A divider between Start, Task View and File Explorer, and the rest of your apps.
  - recycleBin: true
    $name: Recycle Bin
    $description: Show the Recycle Bin at the right end of the dock, after a divider.
  - startButton: true
    $name: Start button
    $description: Show the Windows Start button at the left end of the dock.
  $name: Dock Items
- tray:
  - hideTray: false
    $name: Hide system tray
    $description: Hide the clock, volume, network and tray icons at the right end of the taskbar.
  $name: System Tray
*/
// ==/WindhawkModSettings==

#include <windhawk_utils.h>

#include <shellapi.h>
#include <shellscalingapi.h>
#include <sddl.h>
#include <shlobj.h>

#include <algorithm>
#include <atomic>
#include <charconv>
#include <chrono>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <list>
#include <mutex>
#include <numeric>
#include <optional>
#include <regex>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#undef GetCurrentTime

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Numerics.h>
#include <winrt/Windows.Graphics.Effects.h>
#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>

namespace wadt = winrt::Windows::ApplicationModel::DataTransfer;
namespace wf = winrt::Windows::Foundation;
namespace wux = winrt::Windows::UI::Xaml;
namespace wuxc = winrt::Windows::UI::Xaml::Controls;
namespace wuxh = winrt::Windows::UI::Xaml::Hosting;
namespace wuxi = winrt::Windows::UI::Xaml::Input;
namespace wuxm = winrt::Windows::UI::Xaml::Media;
namespace wuc = winrt::Windows::UI::Composition;
namespace wge = winrt::Windows::Graphics::Effects;
namespace wuxs = winrt::Windows::UI::Xaml::Shapes;

// ---- Settings, as the user set them ----
int g_dockSize = 55;           // 0-100
int g_iconSpacingSetting = 13; // pixels between icons
float g_scale = 1.6f;          // from Magnification Amount: 0-100 -> 1.0-2.0
int g_dockTint = 20;           // 0-100
int g_dockBlur = 35;           // 0-100
int g_dockBottomGapSetting = 7; // pixels
int g_magnificationRange = 55; // 0-100
int g_dockTheme = 0;           // 0 = System (follows Windows), 1 = dark, 2 = light
int g_dockStyle = 0;           // 0 = outline, 1 = inner highlights
int g_animationMs = 100;
bool g_showTrash = true;
bool g_appsDivider = true;
bool g_showStart = true;
bool g_hideTray = false;
bool g_autoHideDock = false;

// ---- Sizes derived from the settings (see ComputeSizes) ----
float g_iconSize = 39.0f;
float g_radius = 130.0f;       // effect radius
float g_buttonWidth = 47.0f;   // widened to fit the icon (see ApplyButtonWidth)
float g_buttonMargin = 2.5f;   // per side; negative pulls buttons together
float g_dockHeight = 65.0f;
float g_dockSidePadding = 15.0f;
float g_dockRadius = 20.0f;
float g_dockBottomGap = 7.0f;
int g_taskbarHeight = 85;      // 0 = leave the taskbar at its normal height
float g_iconLoadSize = 63;     // resolution icons are loaded at; 0 = Windows' own
float g_dividerSpace = 14.0f;  // room for a divider
float g_trashSlot = 48.0f;     // room for the Recycle Bin itself
float g_trashSpace = 62.0f;    // room reserved after the last icon: divider + Recycle Bin

constexpr float kStockIconSize = 24;      // Windows 11 taskbar icon size
constexpr float kStockButtonWidth = 44;   // Windows 11 taskbar button width
constexpr int kMinTaskbarHeight = 40;     // keeps the clock from being squashed
constexpr float kButtonIconPadding = 16;   // a button is at least its icon + this wide

// Windows' Recycle Bin icon has empty space around it (app icons fill their
// square), so it's drawn this much bigger, in the same slot.
constexpr float kTrashIconScale = 1.15f;
// How far a badge sticks out above its icon's top edge, as a fraction of the
// icon size. Sets how much taller than the icons the taskbar window is.
constexpr float kBadgeOverhang = 0.25f;

void ComputeSizes() {
    // Exponential, so every step of the slider feels the same:
    // 0 -> 18px, 20 -> 24px (Windows' own size), 55 -> 39px, 100 -> 73px.
    float icon = std::round(kStockIconSize * std::exp2((g_dockSize - 20) / 50.0f));
    g_iconSize = icon;

    // Ratios that give the original look (40px dock, 12px corners, 4px gap)
    // at the stock 24px icon.
    g_dockHeight = std::round(icon * 5 / 3);
    // Space between the outermost icons and the dock's ends: 15px at the
    // default 39px icon (Size 55).
    g_dockSidePadding = std::round(icon * 0.385f);
    g_dockRadius = std::round(g_dockHeight * 0.3f);
    g_dockBottomGap = (float)g_dockBottomGapSetting;
    // Range 0-100: icons grow up to 1-6 icons from the pointer.
    g_radius = icon * (1 + g_magnificationRange / 20.0f);

    // Buttons stay at the stock width unless the icon needs more room.
    // Visible gap between icons, scaled with the icons. The margins make
    // every button take up exactly icon + gap.
    g_buttonWidth = std::max(kStockButtonWidth, icon + kButtonIconPadding);
    float gap = (float)g_iconSpacingSetting;
    g_buttonMargin = (icon + gap - g_buttonWidth) / 2;

    // After the divider's space, the Recycle Bin takes up a little less than
    // a button (icon + gap), since it's drawn bigger than an icon.
    g_dividerSpace = std::round(icon * 0.35f);
    g_trashSlot = std::round(icon + gap - icon * 0.1f);
    g_trashSpace = g_dividerSpace + g_trashSlot;

    // Icons are loaded at the largest size they're ever shown at: fully
    // magnified. Shown smaller, they're scaled down, which stays sharp.
    g_iconLoadSize = std::ceil(icon * g_scale);

    // Top of the dock or of a fully magnified icon, whichever is higher. A
    // magnified icon grows upward from its bottom edge.
    float dockTop = g_dockBottomGap + g_dockHeight;
    float iconTop = g_dockBottomGap + (g_dockHeight - icon) / 2 + g_scale * icon;
    // A badge (unread count, overlay icon) sticks out above its icon's top
    // edge and is magnified with it. The taskbar window clips everything past
    // its own top, so it's given room for that too.
    float badgeTop = iconTop + kBadgeOverhang * icon * g_scale;
    float highest = std::max({dockTop, iconTop, badgeTop});

    // The taskbar is just tall enough for that (+2px so a magnified icon never
    // touches the edge).
    g_taskbarHeight = std::max((int)std::ceil(highest + 2), kMinTaskbarHeight);
}

// ---------------------------------------------------------------------------
// Shell jobs
// ---------------------------------------------------------------------------
// Shell operations (recycling files, emptying the Recycle Bin) run one at a
// time on a thread pool thread, so their dialogs don't block the taskbar.

std::mutex g_shellJobsLock;
std::vector<std::function<void()>> g_shellJobs;
PTP_WORK g_shellJobWork = nullptr;  // created in Wh_ModInit

void CALLBACK RunShellJob(PTP_CALLBACK_INSTANCE, PVOID, PTP_WORK) {
    std::function<void()> job;
    {
        std::lock_guard lock(g_shellJobsLock);
        if (g_shellJobs.empty()) return;
        job = std::move(g_shellJobs.front());
        g_shellJobs.erase(g_shellJobs.begin());
    }
    HRESULT co = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    job();
    if (SUCCEEDED(co)) CoUninitialize();
}

void QueueShellJob(std::function<void()> job) {
    if (!g_shellJobWork) return;
    {
        std::lock_guard lock(g_shellJobsLock);
        g_shellJobs.push_back(std::move(job));
    }
    SubmitThreadpoolWork(g_shellJobWork);
}

// ---------------------------------------------------------------------------
// The mod's window
// ---------------------------------------------------------------------------
// A hidden window on the taskbar's thread. It receives Recycle Bin change
// notifications and the mod's own posted updates, and the app bars use the
// same class.

constexpr WCHAR kWindowClass[] = L"Windhawk_" WH_MOD_ID;
constexpr UINT kAppBarMessage = WM_APP;              // ABN_* from the shell
constexpr UINT kUpdateOverWindowsMessage = WM_APP + 1;
constexpr UINT kTrashChangedMessage = WM_APP + 2;    // from SHChangeNotifyRegister
constexpr UINT kTrashCheckedMessage = WM_APP + 3;    // from CheckRecycleBin

std::atomic<HWND> g_modWindow = nullptr;

HINSTANCE ModuleInstance() {
    HMODULE module = nullptr;
    GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                          GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                      (LPCWSTR)&ModuleInstance, &module);
    return module;
}

LRESULT CALLBACK ModWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ScheduleOverWindows(bool autoHide);  // see "Magnify over windows"

bool RegisterWindowClass() {
    static bool registered = [] {
        WNDCLASS wc{};
        wc.lpfnWndProc = ModWindowProc;
        wc.hInstance = ModuleInstance();
        wc.lpszClassName = kWindowClass;
        return RegisterClass(&wc) != 0;
    }();
    return registered;
}

// Run on the taskbar's thread.
HWND EnsureModWindow() {
    if (!g_modWindow && RegisterWindowClass()) {
        g_modWindow = CreateWindowEx(0, kWindowClass, L"", 0, 0, 0, 0, 0, HWND_MESSAGE, nullptr,
                                     ModuleInstance(), nullptr);
    }
    return g_modWindow;
}

// ---------------------------------------------------------------------------
// The actual feature
// ---------------------------------------------------------------------------

struct Button {
    winrt::weak_ref<wux::FrameworkElement> element;
    wf::IInspectable originalMargin{nullptr};  // local value, may be UnsetValue
    int64_t marginToken = 0;
    wux::FrameworkElement::SizeChanged_revoker sizeChanged;
    // The button's template root, widened to fit the icon (ApplyButtonWidth).
    winrt::weak_ref<wux::FrameworkElement> root;
    wf::IInspectable originalRootMinWidth{nullptr};
    // Its icon column, for app buttons (ApplyIconColumn): the taskbar's own
    // width, and the one we last set.
    double originalIconColumn = 0;
    double appliedIconColumn = 0;
    // Room on either side, beyond the spacing: for a divider or the Recycle
    // Bin, and to move File Explorer (see LayOutButtons).
    float extraLeft = 0, extraRight = 0;
};

// Containers of event revokers or XAML objects are no_destroy: XAML shuts down
// before globals are destroyed on exit. ResetAll destroys them on unload.
[[clang::no_destroy]] std::optional<std::list<Button>> g_buttons{std::in_place};

Button* FindButton(wux::FrameworkElement const& el) {
    if (!g_buttons) return nullptr;
    for (auto& b : *g_buttons) {
        if (b.element.get() == el) return &b;
    }
    return nullptr;
}

// Sets the side margins that space out the buttons, plus any extra room (see
// LayOutButtons). Only writes when the value changes.
void ApplySpacing(wux::FrameworkElement const& el) {
    Button* b = FindButton(el);
    wux::Thickness want{g_buttonMargin + (b ? b->extraLeft : 0), 0,
                        g_buttonMargin + (b ? b->extraRight : 0), 0};
    auto m = el.Margin();
    if (m.Left != want.Left || m.Top != want.Top || m.Right != want.Right ||
        m.Bottom != want.Bottom) {
        el.Margin(want);
    }
}

// Puts back a property's value as read with ReadLocalValue: the value set
// on the element itself, or none (UnsetValue).
void RestoreLocalValue(wux::FrameworkElement const& el, wux::DependencyProperty const& dp,
                       wf::IInspectable const& value) {
    if (!value || value == wux::DependencyProperty::UnsetValue()) {
        el.ClearValue(dp);
    } else {
        el.SetValue(dp, value);
    }
}

float GetRowOffsetY(wux::DependencyObject const& row);
void PlaceIndicator(wux::FrameworkElement const& button, float s);

// Set while the mod unloads, so the hooks stop touching the taskbar.
extern std::atomic<bool> g_unloading;

// The point a button is magnified around: the bottom edge of its icon. The
// icon is centered in its button, so that's half an icon below the center.
float ButtonPivotY(wux::FrameworkElement const& button) {
    return (float)button.ActualHeight() / 2 + g_iconSize / 2;
}

// ---- Hover name tooltips: horizontal position ----
// Centers the tooltip on the magnified icon. Its height is set by the window
// position hooks (see "B. Hover name tooltips").
void PlaceTooltip(wux::FrameworkElement const& button, float s, float tx) {
    if (g_unloading) return;
    auto raw = wuxc::ToolTipService::GetToolTip(button);
    if (!raw) return;
    auto tip = raw.try_as<wuxc::ToolTip>();
    if (!tip) {
        // The taskbar uses a plain value; wrap it so offsets can be set.
        wuxc::ToolTip wrapper;
        wrapper.Content(raw);
        wuxc::ToolTipService::SetToolTip(button, wrapper);
        tip = wrapper;
    }
    using wuxc::Primitives::PlacementMode;

    double vertical = 0;  // height is handled by the window position hooks

    if (tip.Placement() != PlacementMode::Top) tip.Placement(PlacementMode::Top);
    if (wuxc::ToolTipService::GetPlacement(button) != PlacementMode::Top) {
        wuxc::ToolTipService::SetPlacement(button, PlacementMode::Top);
    }
    if (std::fabs(tip.VerticalOffset() - vertical) > 0.25) tip.VerticalOffset(vertical);
    if (std::fabs(tip.HorizontalOffset() - tx) > 0.25) tip.HorizontalOffset(tx);
}

// Hover name tooltips: gives the button's tooltip back its own placement.
void RestoreTooltip(wux::FrameworkElement const& button) {
    try {
        button.ClearValue(wuxc::ToolTipService::PlacementProperty());
        if (auto tip = wuxc::ToolTipService::GetToolTip(button).try_as<wuxc::ToolTip>()) {
            tip.ClearValue(wuxc::ToolTip::PlacementProperty());
            tip.ClearValue(wuxc::ToolTip::VerticalOffsetProperty());
            tip.ClearValue(wuxc::ToolTip::HorizontalOffsetProperty());
            tip.ClearValue(wuxc::ToolTip::PlacementRectProperty());
        }
    } catch (...) {}
}

// Scales the icon from its bottom edge, shifts it sideways by `tx`, and moves
// it down onto the dock. Doesn't change the taskbar's layout.
void SetScale(wux::FrameworkElement const& el, float s, float tx = 0) {
    auto visual = wuxh::ElementCompositionPreview::GetElementVisual(el);
    visual.CenterPoint({(float)el.ActualWidth() / 2, ButtonPivotY(el), 0});
    visual.Scale({s, s, 1});
    float ty = GetRowOffsetY(wuxm::VisualTreeHelper::GetParent(el));
    wuxh::ElementCompositionPreview::SetIsTranslationEnabled(el, true);
    visual.Properties().InsertVector3(L"Translation", {tx, ty, 0});
    // Everything inside the button moves with it; the running indicator gets
    // pulled back down to the bottom of the dock.
    PlaceIndicator(el, s);
    try { PlaceTooltip(el, s, tx); } catch (...) {}
}

// The row of icons the pointer is currently over. Its positions are re-read
// every frame (see OnFrame), so it follows apps opening, closing and being
// dragged to a new spot.
struct RowItem {
    winrt::weak_ref<wux::FrameworkElement> element;
    float center = 0;  // horizontal center, in the row's coordinates
    float width = 0;
    float scale = 1.0f;
    float shift = 0;
    bool trash = false;  // the Recycle Bin, which isn't a taskbar button
};

std::vector<RowItem> g_row;
winrt::weak_ref<wux::UIElement> g_rowParent;

// Latest pointer state. Pointer events only write these; the per-frame
// update below reads them.
bool g_pointerOver = false;
bool g_dockExpanded = false;  // icons magnified or about to be (see ClipTaskbars)
float g_pointerX = 0;

// Which end of the dock stays put as it grows and shrinks, and the most it
// has grown during this hover (see OnFrame).
bool g_anchorLeftEnd = true;
float g_maxGrowth = 0, g_lastGrowth = 0;

// ---- Where popups above the dock go ----
// Hover previews and name tooltips are moved down from the top of the tall
// taskbar window to just above the dock (or the biggest magnified icon). See
// "Popups above the dock".
constexpr float kPreviewGap = 6;  // px between a popup and the icon

// How far the top of the dock's tallest icon is above the bottom of the
// screen, in DIPs: the dock's top when nothing is magnified, otherwise the top
// of the biggest magnified icon.
float DockTopInset() {
    float maxScale = 1.0f;
    for (auto& item : g_row) maxScale = std::max(maxScale, item.scale);
    float iconTop = g_dockBottomGap + (g_dockHeight - g_iconSize) / 2 + maxScale * g_iconSize;
    return std::max(g_dockBottomGap + g_dockHeight, iconTop);
}

float PopupShiftDips() {
    return std::max(0.0f, (float)g_taskbarHeight - (DockTopInset() + kPreviewGap));
}

// ---- Hidden taskbar background ----

struct HiddenBackground {
    winrt::weak_ref<wux::FrameworkElement> element;
    double originalOpacity = 1.0;
};

std::list<HiddenBackground> g_backgrounds;

// Makes the taskbar's background invisible (opacity 0), remembering how to
// put it back. Opacity rather than Collapsed, so it still catches clicks on
// the taskbar's empty space.
void HideBackground(wux::FrameworkElement const& el) {
    if (el.Name() != L"BackgroundControl") return;
    g_backgrounds.remove_if([](HiddenBackground const& b) { return !b.element.get(); });
    for (auto& b : g_backgrounds) {
        if (b.element.get() == el) return;
    }
    g_backgrounds.push_back({winrt::make_weak(el), el.Opacity()});
    el.Opacity(0);
    Wh_Log(L"Taskbar background hidden");
}

void RestoreHidden(HiddenBackground const& b) {
    if (auto el = b.element.get()) {
        try { el.Opacity(b.originalOpacity); } catch (...) {}
    }
}

void RestoreBackgrounds() {
    for (auto& b : g_backgrounds) RestoreHidden(b);
    g_backgrounds.clear();
}

// ---- Finding the taskbar's elements ----

// Calls `f` for every element under `parent`, at most `depth` levels down.
// `f` returns false to skip that element's own children.
template <typename F>
void ForEachDescendant(wux::DependencyObject const& parent, int depth, F& f) {
    int count = wuxm::VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < count; i++) {
        auto child = wuxm::VisualTreeHelper::GetChild(parent, i);
        bool descend = true;
        if (auto el = child.try_as<wux::FrameworkElement>()) descend = f(el);
        if (descend && depth > 1) ForEachDescendant(child, depth - 1, f);
    }
}

// The taskbar (Taskbar.TaskbarFrame) that `el` is in, or null.
wux::FrameworkElement FindTaskbarFrame(wux::FrameworkElement const& el) {
    wux::DependencyObject current = el;
    for (int depth = 0; current && depth < 20; depth++) {
        if (winrt::get_class_name(current) == L"Taskbar.TaskbarFrame") {
            return current.try_as<wux::FrameworkElement>();
        }
        current = wuxm::VisualTreeHelper::GetParent(current);
    }
    return nullptr;
}

// ---- Button highlight ----
// Hides the box behind hovered/active icons ("BackgroundElement" and
// "MultiWindowElement"). The taskbar animates their opacity, so they're also
// collapsed, and hidden again if the taskbar changes either property.

struct HiddenHighlight {
    winrt::weak_ref<wux::FrameworkElement> element;
    double originalOpacity = 1.0;
    wux::Visibility originalVisibility = wux::Visibility::Visible;
    int64_t opacityToken = 0, visibilityToken = 0;
};

std::vector<HiddenHighlight> g_highlights;

void ApplyHighlightHidden(wux::UIElement const& el) {
    if (el.Opacity() != 0) el.Opacity(0);
    if (el.Visibility() != wux::Visibility::Collapsed) el.Visibility(wux::Visibility::Collapsed);
}

void HideHighlight(wux::FrameworkElement const& el) {
    // Forget the highlights of buttons that are gone.
    g_highlights.erase(std::remove_if(g_highlights.begin(), g_highlights.end(),
                                      [](HiddenHighlight& h) { return !h.element.get(); }),
                       g_highlights.end());
    for (auto& h : g_highlights) {
        if (h.element.get() == el) return;
    }
    auto& h = g_highlights.emplace_back();
    h.element = winrt::make_weak(el);
    h.originalOpacity = el.Opacity();
    h.originalVisibility = el.Visibility();
    auto rehide = [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
        try {
            if (auto ui = sender.try_as<wux::UIElement>()) ApplyHighlightHidden(ui);
        } catch (...) {}
    };
    h.opacityToken = el.RegisterPropertyChangedCallback(wux::UIElement::OpacityProperty(), rehide);
    h.visibilityToken =
        el.RegisterPropertyChangedCallback(wux::UIElement::VisibilityProperty(), rehide);
    ApplyHighlightHidden(el);
}

void RestoreHighlights() {
    for (auto& h : g_highlights) {
        auto el = h.element.get();
        if (!el) continue;
        try {
            el.UnregisterPropertyChangedCallback(wux::UIElement::OpacityProperty(),
                                                 h.opacityToken);
            el.UnregisterPropertyChangedCallback(wux::UIElement::VisibilityProperty(),
                                                 h.visibilityToken);
            el.Opacity(h.originalOpacity);
            el.Visibility(h.originalVisibility);
        } catch (...) {}
    }
    g_highlights.clear();
}

// ---- Icon size ----
// Sizes each button's "Icon" image to the dock's icon size, and re-applies it
// if the taskbar resets it. Resizing the image (instead of scaling the button)
// keeps the icon sharp.

struct IconImage {
    winrt::weak_ref<wux::FrameworkElement> element;
    wf::IInspectable originalWidth{nullptr};   // local values, may be UnsetValue
    wf::IInspectable originalHeight{nullptr};
    int64_t widthToken = 0, heightToken = 0;
};

[[clang::no_destroy]] std::optional<std::list<IconImage>> g_iconImages{std::in_place};

void ApplyIconSize(wux::FrameworkElement const& el) {
    // Width() is NaN when unset, and NaN != anything, so this also covers it.
    if (el.Width() != g_iconSize) el.Width(g_iconSize);
    if (el.Height() != g_iconSize) el.Height(g_iconSize);
}

void TrackIconImage(wux::FrameworkElement const& el) {
    for (auto& i : *g_iconImages) {
        if (i.element.get() == el) return;
    }
    auto& i = g_iconImages->emplace_back();
    i.element = winrt::make_weak(el);
    i.originalWidth = el.ReadLocalValue(wux::FrameworkElement::WidthProperty());
    i.originalHeight = el.ReadLocalValue(wux::FrameworkElement::HeightProperty());
    auto reapply = [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
        try {
            if (auto fe = sender.try_as<wux::FrameworkElement>()) ApplyIconSize(fe);
        } catch (...) {}
    };
    i.widthToken =
        el.RegisterPropertyChangedCallback(wux::FrameworkElement::WidthProperty(), reapply);
    i.heightToken =
        el.RegisterPropertyChangedCallback(wux::FrameworkElement::HeightProperty(), reapply);
    ApplyIconSize(el);
}

// Undoes TrackIconImage for one image.
void ReleaseIconImage(IconImage const& i) {
    auto el = i.element.get();
    if (!el) return;
    try {
        el.UnregisterPropertyChangedCallback(wux::FrameworkElement::WidthProperty(),
                                             i.widthToken);
        el.UnregisterPropertyChangedCallback(wux::FrameworkElement::HeightProperty(),
                                             i.heightToken);
        RestoreLocalValue(el, wux::FrameworkElement::WidthProperty(), i.originalWidth);
        RestoreLocalValue(el, wux::FrameworkElement::HeightProperty(), i.originalHeight);
    } catch (...) {}
}

void RestoreIconImages() {
    for (auto& i : *g_iconImages) ReleaseIconImage(i);
    g_iconImages->clear();
}

// ---- Badge (overlay icon) ----
// The "OverlayIcon" image is aligned to the top-right of the button, which is
// as tall as the taskbar. Its margin is set so it sits on the icon's top-right
// corner, and re-applied when the taskbar or panel changes it.

struct OverlayBadge {
    winrt::weak_ref<wux::FrameworkElement> element;
    winrt::weak_ref<wux::FrameworkElement> panel;
    wf::IInspectable originalMargin{nullptr};  // local value, may be UnsetValue
    int64_t marginToken = 0;
    wux::FrameworkElement::SizeChanged_revoker panelSizeChanged;
};

[[clang::no_destroy]] std::optional<std::list<OverlayBadge>> g_badges{std::in_place};

// How much of the badge sticks out past the icon's corner.
constexpr double kBadgeOutside = 0.4;

// Extra pixels to lift the badge above the icon's corner (at normal size).
constexpr double kBadgeLift = 3;

// Extra pixels to pull the badge left, toward the icon (at normal size).
constexpr double kBadgeLeft = 1;

void ApplyBadgePosition(wux::FrameworkElement const& el, wux::FrameworkElement const& panel) {
    double panelHeight = panel.ActualHeight();
    if (panelHeight <= 0) return;  // not laid out yet; the SizeChanged below tries again
    double badgeW = el.ActualWidth() > 0 ? el.ActualWidth() : 16;
    double badgeH = el.ActualHeight() > 0 ? el.ActualHeight() : 16;

    // The icon's column: the button's width, less the panel's padding.
    double columnWidth = g_buttonWidth;
    if (auto grid = panel.try_as<wuxc::Grid>()) {
        auto padding = grid.Padding();
        columnWidth -= padding.Left + padding.Right;
    }
    wux::Thickness want{0, std::max(0.0, (panelHeight - g_iconSize) / 2 - badgeH * kBadgeOutside - kBadgeLift),
                        (columnWidth - g_iconSize) / 2 - badgeW * kBadgeOutside + kBadgeLeft, 0};
    auto m = el.Margin();
    if (m.Left != want.Left || m.Top != want.Top || m.Right != want.Right ||
        m.Bottom != want.Bottom) {
        el.Margin(want);
    }
}

void TrackBadge(wux::FrameworkElement const& el) {
    for (auto& b : *g_badges) {
        if (b.element.get() == el) return;
    }
    auto panel = wuxm::VisualTreeHelper::GetParent(el).try_as<wux::FrameworkElement>();
    if (!panel) return;
    auto& b = g_badges->emplace_back();
    b.element = winrt::make_weak(el);
    b.panel = winrt::make_weak(panel);
    b.originalMargin = el.ReadLocalValue(wux::FrameworkElement::MarginProperty());
    b.marginToken = el.RegisterPropertyChangedCallback(
        wux::FrameworkElement::MarginProperty(),
        [weakPanel = b.panel](wux::DependencyObject const& sender,
                              wux::DependencyProperty const&) {
            try {
                auto fe = sender.try_as<wux::FrameworkElement>();
                auto p = weakPanel.get();
                if (fe && p) ApplyBadgePosition(fe, p);
            } catch (...) {}
        });
    b.panelSizeChanged = panel.SizeChanged(
        winrt::auto_revoke, [weakEl = b.element](wf::IInspectable const& sender,
                                                 wux::SizeChangedEventArgs const&) {
            try {
                auto fe = weakEl.get();
                auto p = sender.try_as<wux::FrameworkElement>();
                if (fe && p) ApplyBadgePosition(fe, p);
            } catch (...) {}
        });
    ApplyBadgePosition(el, panel);
}

void RestoreBadges() {
    for (auto& b : *g_badges) {
        b.panelSizeChanged.revoke();
        auto el = b.element.get();
        if (!el) continue;
        try {
            if (b.marginToken) {
                el.UnregisterPropertyChangedCallback(wux::FrameworkElement::MarginProperty(),
                                                     b.marginToken);
            }
            RestoreLocalValue(el, wux::FrameworkElement::MarginProperty(), b.originalMargin);
        } catch (...) {}
    }
    g_badges->clear();
}

// A visible taskbar button and where it sits inside its row.
struct Icon {
    wux::FrameworkElement element{nullptr};
    float left = 0;  // in the row's coordinates
    float top = 0;
    float width = 0;
    float height = 0;
    // The space the taskbar laid it out in, margins included. These tile the
    // row in the taskbar's own order, whatever the margins move the buttons to.
    float slotLeft = 0, slotWidth = 0;
};

// All visible tracked buttons whose parent is `parent`.
std::vector<Icon> GetIcons(wux::UIElement const& parent) {
    std::vector<Icon> icons;
    for (auto& b : *g_buttons) {
        auto other = b.element.get();
        if (!other || other.Visibility() != wux::Visibility::Visible ||
            other.ActualWidth() <= 0) {
            continue;
        }
        if (wuxm::VisualTreeHelper::GetParent(other) != parent) continue;
        // Where the taskbar laid the button out. Unlike TransformToVisual,
        // this ignores the scaling/shifting we apply, so measurements taken
        // while icons are magnified are still correct.
        auto slot = wuxc::Primitives::LayoutInformation::GetLayoutSlot(other);
        auto margin = other.Margin();
        float x = slot.X + (float)margin.Left;
        float y = slot.Y + (float)margin.Top;
        // Skip recycled buttons parked out of view by the taskbar.
        if (y < -other.ActualHeight() || y > other.ActualHeight()) continue;
        icons.push_back({other, x, y, (float)other.ActualWidth(), (float)other.ActualHeight(),
                         slot.X, slot.Width});
    }
    return icons;
}

// ---- Dock plate: a rounded box drawn behind each taskbar's icons ----

// Blur 100 = this much Gaussian blur. 50 gives 30, the same as Windows' own
// acrylic material.
constexpr float kMaxBlur = 60;

// A Gaussian blur effect for Windows.UI.Composition. Explorer doesn't ship
// Win2D, so the effect is described directly to Direct2D.
enum DOCK_EFFECT_PROPERTY_MAPPING : int {
    DOCK_EFFECT_PROPERTY_MAPPING_UNKNOWN = 0,
    DOCK_EFFECT_PROPERTY_MAPPING_DIRECT = 1,
};

MIDL_INTERFACE("2FC57384-A068-44D7-A331-30982FCF7177")
IDockGraphicsEffectD2D1Interop : public IUnknown {
public:
    virtual HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetNamedPropertyMapping(
        LPCWSTR name, UINT* index, DOCK_EFFECT_PROPERTY_MAPPING* mapping) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetProperty(UINT index, void** value) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSource(UINT index, void** source) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) = 0;
};
__CRT_UUID_DECL(IDockGraphicsEffectD2D1Interop, 0x2fc57384, 0xa068, 0x44d7, 0xa3, 0x31, 0x30,
                0x98, 0x2f, 0xcf, 0x71, 0x77)

// CLSID_D2D1GaussianBlur
constexpr GUID kGaussianBlurId = {
    0x1feb6d69, 0x2fe6, 0x4ac9, {0x8c, 0x58, 0x1d, 0x7f, 0x93, 0xe7, 0xa6, 0xa5}};

class GaussianBlurEffect
    : public winrt::implements<GaussianBlurEffect, wge::IGraphicsEffect,
                               wge::IGraphicsEffectSource, IDockGraphicsEffectD2D1Interop> {
public:
    GaussianBlurEffect(float amount, wge::IGraphicsEffectSource const& source)
        : m_amount(amount), m_source(source) {}

    winrt::hstring Name() { return m_name; }
    void Name(winrt::hstring const& name) { m_name = name; }

    HRESULT STDMETHODCALLTYPE GetEffectId(GUID* id) override {
        *id = kGaussianBlurId;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetNamedPropertyMapping(
        LPCWSTR name, UINT* index, DOCK_EFFECT_PROPERTY_MAPPING* mapping) override {
        if (_wcsicmp(name, L"BlurAmount") != 0) return E_INVALIDARG;
        *index = 0;
        *mapping = DOCK_EFFECT_PROPERTY_MAPPING_DIRECT;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetPropertyCount(UINT* count) override {
        *count = 3;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetProperty(UINT index, void** value) override {
        try {
            wf::IInspectable v;
            switch (index) {
                case 0: v = wf::PropertyValue::CreateSingle(m_amount); break;  // std. deviation
                case 1: v = wf::PropertyValue::CreateUInt32(1); break;  // optimization: balanced
                case 2: v = wf::PropertyValue::CreateUInt32(1); break;  // border mode: hard
                default: return E_INVALIDARG;
            }
            *value = winrt::detach_abi(v.as<wf::IPropertyValue>());
            return S_OK;
        } catch (...) {
            return winrt::to_hresult();
        }
    }
    HRESULT STDMETHODCALLTYPE GetSource(UINT index, void** source) override {
        if (index != 0) return E_INVALIDARG;
        winrt::copy_to_abi(m_source, *source);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetSourceCount(UINT* count) override {
        *count = 1;
        return S_OK;
    }

private:
    float m_amount;
    wge::IGraphicsEffectSource m_source;
    winrt::hstring m_name;
};

// Puts a blurred copy of what's behind `host` inside it, with rounded
// corners. Returns the corner shape so its radius can be changed later, or
// nothing when the blur is off.
wuc::CompositionRoundedRectangleGeometry SetBlurVisual(wux::UIElement const& host, float amount) {
    if (amount <= 0) {
        wuxh::ElementCompositionPreview::SetElementChildVisual(host, nullptr);
        return nullptr;
    }
    auto hostVisual = wuxh::ElementCompositionPreview::GetElementVisual(host);
    auto compositor = hostVisual.Compositor();

    auto effect = winrt::make<GaussianBlurEffect>(
        amount, wuc::CompositionEffectSourceParameter(L"Backdrop"));
    auto brush = compositor.CreateEffectFactory(effect).CreateBrush();
    brush.SetSourceParameter(L"Backdrop", compositor.CreateBackdropBrush());

    auto sprite = compositor.CreateSpriteVisual();
    sprite.Brush(brush);

    // Follow the host element's size, and clip to the dock's rounded shape.
    auto size = compositor.CreateExpressionAnimation(L"host.Size");
    size.SetReferenceParameter(L"host", hostVisual);
    sprite.StartAnimation(L"Size", size);
    auto shape = compositor.CreateRoundedRectangleGeometry();
    shape.CornerRadius({g_dockRadius, g_dockRadius});
    shape.StartAnimation(L"Size", size);
    sprite.Clip(compositor.CreateGeometricClip(shape));

    wuxh::ElementCompositionPreview::SetElementChildVisual(host, sprite);
    return shape;
}

// The plate is two layers in a grid: the blur at the bottom, and the tint and
// outline on top of it.
struct Plate {
    winrt::weak_ref<wux::UIElement> row;     // the icons' parent
    winrt::weak_ref<wuxc::Panel> panel;      // the row's parent; the plate lives here
    wuxc::Grid root{nullptr};                // gets positioned and sized
    wuxc::Border blurHost{nullptr};
    wuxc::Border tint{nullptr};
    wuxc::Border highlightTop{nullptr};
    winrt::weak_ref<wux::FrameworkElement> frame;  // the taskbar it's in
    wuc::CompositionRoundedRectangleGeometry blurShape{nullptr};
    float appliedBlur = -1;
    float baseLeft = 0, baseWidth = 0;       // size when nothing is magnified
    float top = 0;
    float left = -1, width = -1;             // last applied
    float offsetY = 0;                       // how far the row's icons are moved down
    float dockBottom = 0;                    // bottom edge of the dock, in the row's coordinates
    wux::FrameworkElement::SizeChanged_revoker rowSizeChanged;
    wux::FrameworkElement::SizeChanged_revoker panelSizeChanged;
    wux::FrameworkElement::ActualThemeChanged_revoker panelThemeChanged;
    // The Recycle Bin at the dock's right end, after a divider. They aren't
    // in the row (the taskbar owns it); they sit in the panel over the space
    // reserved after the last button (see LayOutButtons).
    wuxc::Grid trash{nullptr};
    wuxc::Image trashImage{nullptr};
    wuxc::Border divider{nullptr};
    wux::UIElement::Tapped_revoker trashTapped;
    wux::UIElement::RightTapped_revoker trashRightTapped;
    wux::UIElement::DragEnter_revoker trashDragEnter;
    wux::UIElement::DragOver_revoker trashDragOver;
    wux::UIElement::Drop_revoker trashDrop;
    winrt::weak_ref<wux::FrameworkElement> beforeTrash;  // the last button
    float trashCenter = 0;  // in the row's coordinates
    int trashState = -2;    // icon shown: -1 unknown, 0 empty, 1 full
    // The divider between Start, Task View, File Explorer and the other apps,
    // in the space reserved after the button before it (see AppsDividerButton).
    wuxc::Border appsDivider{nullptr};
    winrt::weak_ref<wux::FrameworkElement> beforeAppsDivider;
    float appsDividerShift = 0;  // last applied, for magnification
};

[[clang::no_destroy]] std::optional<std::list<Plate>> g_plates{std::in_place};

Plate* GetRowPlate(wux::DependencyObject const& row) {
    if (!row) return nullptr;
    for (auto& p : *g_plates) {
        if (p.row.get() == row) return &p;
    }
    return nullptr;
}

bool IsFileExplorer(wux::FrameworkElement const& button) {
    return wux::Automation::AutomationProperties::GetAutomationId(button) ==
           L"Appid: Microsoft.Windows.Explorer";
}

// The button the apps divider goes after: File Explorer if it's the first app,
// otherwise the last system button (Start, Task View). Null if there's nothing
// on one side.
wux::FrameworkElement AppsDividerButton(std::vector<wux::FrameworkElement> const& buttons) {
    size_t i = 0;
    while (i < buttons.size() && winrt::get_class_name(buttons[i]) != L"Taskbar.TaskListButton") {
        i++;
    }
    if (i < buttons.size() && IsFileExplorer(buttons[i])) i++;
    // The divider goes just before buttons[i].
    if (i == 0 || i >= buttons.size()) return nullptr;
    return buttons[i - 1];
}

// Moves the apps divider with the magnification's spreading.
void SetAppsDividerShift(Plate& p, float tx) {
    if (!p.appsDivider || std::fabs(tx - p.appsDividerShift) < 0.01f) return;
    p.appsDividerShift = tx;
    auto visual = wuxh::ElementCompositionPreview::GetElementVisual(p.appsDivider);
    wuxh::ElementCompositionPreview::SetIsTranslationEnabled(p.appsDivider, true);
    visual.Properties().InsertVector3(L"Translation", {tx, 0, 0});
}

// How far the icons in `row` are moved down to sit on its dock plate.
float GetRowOffsetY(wux::DependencyObject const& row) {
    Plate* p = GetRowPlate(row);
    return p ? p->offsetY : 0;
}

// Frames left in which to re-measure the plates. Set when buttons come or go,
// and counted down over a few frames so the taskbar has laid them out first.
int g_platesDirtyFrames = 0;

void StartFrames();

void MarkPlatesDirty() {
    g_platesDirtyFrames = 3;
    StartFrames();
}

// Frosted glass: the desktop behind the dock, blurred (Blur), under a
// translucent color (Tint), dark or light (Color). The dividers are drawn in
// the opposite color.
void ApplyPlateLook(Plate& p) {
    bool light = g_dockTheme == 2;
    if (g_dockTheme == 0) {
        auto panel = p.panel.get();
        light = panel && panel.ActualTheme() == wux::ElementTheme::Light;
    }
    using winrt::Windows::UI::Color;
    uint8_t alpha = (uint8_t)(g_dockTint * 255 / 100);
    Color tint = light ? Color{alpha, 245, 245, 247} : Color{alpha, 60, 60, 65};
    Color border = light ? Color{30, 0, 0, 0} : Color{40, 255, 255, 255};
    Color line = light ? Color{70, 0, 0, 0} : Color{90, 255, 255, 255};
    for (auto& divider : {p.divider, p.appsDivider}) {
        if (divider) divider.Background(wuxm::SolidColorBrush(line));
    }
    p.tint.Background(wuxm::SolidColorBrush(tint));
    p.tint.BorderBrush(wuxm::SolidColorBrush(border));
    p.tint.BorderThickness({1, 1, 1, 1});
    bool highlights = g_dockStyle == 1;
    if (p.highlightTop) {
        p.highlightTop.BorderThickness({0, 0, 0, 0});
        if (!highlights) {
            p.highlightTop.Visibility(wux::Visibility::Collapsed);
        } else {
            Color clear{0, 255, 255, 255};
            // The same color at a fraction of its strength, for a soft falloff.
            auto fade = [](Color c, double k) {
                c.A = (uint8_t)(c.A * k);
                return c;
            };
            auto addStop = [](wuxm::LinearGradientBrush const& brush, double offset, Color color) {
                wuxm::GradientStop stop;
                stop.Color(color);
                stop.Offset(offset);
                brush.GradientStops().Append(stop);
            };

            // ---- Soft inner glow (the wide, blurry highlight) ----
            // How deep it goes, as a fraction of the dock's height.
            double depthTop = 0.08;
            double depthBottom = 0.10;
            Color glowTop = light ? Color{48, 255, 255, 255} : Color{27, 255, 255, 255};
            Color glowBottom = light ? Color{12, 0, 0, 0} : Color{13, 255, 255, 255};

            wuxm::LinearGradientBrush glow;
            glow.StartPoint({0, 0});
            glow.EndPoint({0, 1});
            addStop(glow, 0.0, glowTop);
            addStop(glow, depthTop * 0.4, fade(glowTop, 0.3));
            addStop(glow, depthTop, clear);
            addStop(glow, 1.0 - depthBottom, clear);
            addStop(glow, 1.0 - depthBottom * 0.4, fade(glowBottom, 0.3));
            addStop(glow, 1.0, glowBottom);

            p.highlightTop.Height(std::numeric_limits<double>::quiet_NaN());
            p.highlightTop.VerticalAlignment(wux::VerticalAlignment::Stretch);
            p.highlightTop.Margin({0, 0, 0, 0});
            p.highlightTop.CornerRadius({g_dockRadius, g_dockRadius, g_dockRadius, g_dockRadius});
            p.highlightTop.Background(glow);
            p.highlightTop.Visibility(wux::Visibility::Visible);

            // ---- Crisp rim (the sharp highlight that curls round the corners) ----
            // How far the highlight wraps down the corners, as a fraction of
            // the dock's height (0.30 follows the whole curve).
            double edgeWrap = 0.30;
            Color edgeTop = light ? Color{27, 255, 255, 255} : Color{30, 255, 255, 255};
            Color edgeBottom = light ? Color{27, 0, 0, 0} : Color{36, 255, 255, 255};

            wuxm::LinearGradientBrush rim;
            rim.StartPoint({0, 0});
            rim.EndPoint({0, 1});
            addStop(rim, 0.0, edgeTop);
            addStop(rim, edgeWrap * 0.5, fade(edgeTop, 0.35));
            addStop(rim, edgeWrap, clear);
            addStop(rim, 1.0 - edgeWrap, clear);
            addStop(rim, 1.0 - edgeWrap * 0.5, fade(edgeBottom, 0.35));
            addStop(rim, 1.0, edgeBottom);
            p.tint.BorderBrush(rim);
        }
    }
    p.tint.CornerRadius({g_dockRadius, g_dockRadius, g_dockRadius, g_dockRadius});

    float blur = g_dockBlur * kMaxBlur / 100;
    if (blur != p.appliedBlur) {
        p.appliedBlur = blur;
        try {
            p.blurShape = SetBlurVisual(p.blurHost, blur);
        } catch (...) {
            p.blurShape = nullptr;
            Wh_Log(L"Dock blur failed: 0x%08X %s", winrt::to_hresult(),
                   winrt::to_message().c_str());
        }
    } else if (p.blurShape) {
        p.blurShape.CornerRadius({g_dockRadius, g_dockRadius});
    }
}

void StartTrash();
void UpdateTrashIcons();
void HookUpTrash(Plate& p);

// Lays `el` out from the panel's top-left corner, positioned by its margin
// (spanning the whole grid, if it's one, so that's where it's measured from).
void PlaceInPanel(wuxc::Panel const& panel, wux::FrameworkElement const& el) {
    el.HorizontalAlignment(wux::HorizontalAlignment::Left);
    el.VerticalAlignment(wux::VerticalAlignment::Top);
    el.Visibility(wux::Visibility::Collapsed);
    if (panel.try_as<wuxc::Grid>()) {
        wuxc::Grid::SetRowSpan(el, 100);
        wuxc::Grid::SetColumnSpan(el, 100);
    }
}

// A thin vertical line, an icon tall. Put right after the icon row (like the
// Recycle Bin) so it's drawn above it.
wuxc::Border AddDivider(wuxc::Panel const& panel, wux::UIElement const& row) {
    wuxc::Border divider;
    PlaceInPanel(panel, divider);
    divider.IsHitTestVisible(false);
    divider.Width(1);
    divider.Height(g_iconSize);
    uint32_t index = 0;
    if (!panel.Children().IndexOf(row, index)) return nullptr;
    panel.Children().InsertAt(index + 1, divider);
    return divider;
}

// The divider and the Recycle Bin.
void AddTrash(Plate& p, wuxc::Panel const& panel, wux::UIElement const& row) {
    wuxc::Grid trash;
    PlaceInPanel(panel, trash);
    trash.Width(g_iconSize * kTrashIconScale);
    trash.Height(g_iconSize * kTrashIconScale);
    // A transparent background makes the whole square clickable.
    trash.Background(wuxm::SolidColorBrush(winrt::Windows::UI::Color{0, 0, 0, 0}));
    wuxc::ToolTipService::SetToolTip(trash, winrt::box_value(L"Recycle Bin"));
    wuxc::Image image;
    image.Stretch(wuxm::Stretch::Uniform);
    trash.Children().Append(image);

    uint32_t index = 0;
    if (!panel.Children().IndexOf(row, index)) return;
    panel.Children().InsertAt(index + 1, trash);
    auto divider = AddDivider(panel, row);

    p.trash = trash;
    p.trashImage = image;
    p.divider = divider;
    HookUpTrash(p);
    StartTrash();
}

void EnsurePlate(wux::FrameworkElement const& button) {
    // Only rows in a taskbar: not, say, the overflow flyout's.
    if (!FindTaskbarFrame(button)) return;
    auto row = wuxm::VisualTreeHelper::GetParent(button).try_as<wux::FrameworkElement>();
    if (!row) return;
    for (auto& p : *g_plates) {
        if (p.row.get() == row) return;
    }
    auto panel = wuxm::VisualTreeHelper::GetParent(row).try_as<wuxc::Panel>();
    if (!panel) {
        Wh_Log(L"The icon row's parent isn't a panel; no dock plate");
        return;
    }

    wuxc::Grid root;
    PlaceInPanel(panel, root);
    root.IsHitTestVisible(false);
    wuxc::Border blurHost;
    wuxc::Border tint;
    root.Children().Append(blurHost);
    root.Children().Append(tint);  // later children draw on top
    wuxc::Border highlightTop;
    highlightTop.Height(1);
    highlightTop.VerticalAlignment(wux::VerticalAlignment::Top);
    highlightTop.IsHitTestVisible(false);
    highlightTop.Visibility(wux::Visibility::Collapsed);
    root.Children().Append(highlightTop);
    // No layout rounding: rounding the plate's left edge and width separately
    // made its right edge jitter (see ApplyPlate).
    for (wux::FrameworkElement el : {wux::FrameworkElement(root), wux::FrameworkElement(blurHost),
                                     wux::FrameworkElement(tint)}) {
        el.UseLayoutRounding(false);
    }

    // Insert it right before the icon row: drawn above whatever comes earlier
    // (the taskbar background), below the icons.
    uint32_t index = 0;
    if (!panel.Children().IndexOf(row, index)) index = 0;
    panel.Children().InsertAt(index, root);

    auto& p = g_plates->emplace_back();
    p.row = winrt::make_weak(row.as<wux::UIElement>());
    p.panel = winrt::make_weak(panel);
    p.root = root;
    p.blurHost = blurHost;
    p.tint = tint;
    p.highlightTop = highlightTop;

    auto onSize = [](wf::IInspectable const&, wux::SizeChangedEventArgs const&) {
        MarkPlatesDirty();
    };
    p.rowSizeChanged = row.SizeChanged(winrt::auto_revoke, onSize);
    p.panelSizeChanged = panel.SizeChanged(winrt::auto_revoke, onSize);
    if (g_showTrash) AddTrash(p, panel, row);
    if (g_appsDivider) p.appsDivider = AddDivider(panel, row);
    ApplyPlateLook(p);
    // Windows switched between light and dark mode (for System).
    p.panelThemeChanged = panel.ActualThemeChanged(
        winrt::auto_revoke, [](wux::FrameworkElement const&, wf::IInspectable const&) {
            for (auto& plate : *g_plates) {
                try { ApplyPlateLook(plate); } catch (...) {}
            }
        });
    Wh_Log(L"Dock plate added");
}

// Re-applies a button's transform with its current magnification.
void ReapplyButton(wux::FrameworkElement const& button) {
    float s = 1.0f, tx = 0;
    for (auto& item : g_row) {
        if (item.element.get() == button) {
            s = item.scale;
            tx = item.shift;
            break;
        }
    }
    SetScale(button, s, tx);
}

// Works out the extra room each button gets beyond the spacing and applies it
// (see ApplySpacing). `icons` are the row's buttons in any order. Returns the
// buttons the Recycle Bin and the apps divider go after.
//
// - Recycle Bin and its divider: room after the last button.
// - Apps divider: room after its button (see AppsDividerButton).
// - File Explorer, when it isn't the first app: the first app gets room before
//   it, and File Explorer is moved into that room with margins, leaving the
//   other buttons where they are.
std::pair<wux::FrameworkElement, wux::FrameworkElement> LayOutButtons(
    Plate& p, std::vector<Icon> const& icons) {
    // The taskbar's own order. A moved File Explorer's space is zero wide,
    // at the same place as the next one's, which it comes before.
    std::vector<size_t> order(icons.size());
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](size_t a, size_t b) {
        if (icons[a].slotLeft != icons[b].slotLeft) return icons[a].slotLeft < icons[b].slotLeft;
        return icons[a].slotWidth < icons[b].slotWidth;
    });

    constexpr size_t kNone = SIZE_MAX;
    size_t firstApp = kNone, explorer = kNone;
    for (size_t i : order) {
        if (winrt::get_class_name(icons[i].element) != L"Taskbar.TaskListButton") continue;
        if (firstApp == kNone) firstApp = i;
        if (explorer == kNone && IsFileExplorer(icons[i].element)) explorer = i;
    }
    bool moveExplorer = explorer != kNone && explorer != firstApp;

    std::vector<float> left(icons.size()), right(icons.size());
    size_t last = order.back();  // as shown
    if (moveExplorer && last == explorer) last = order[order.size() - 2];
    if (p.trash) right[last] += g_trashSpace;

    wux::FrameworkElement beforeAppsDivider{nullptr};
    float dividerSpace = p.appsDivider ? g_dividerSpace : 0;
    if (moveExplorer) {
        // Its button stretches to fill the room it's given, so the room is
        // worked out from the button width, not from its measured one.
        auto& e = icons[explorer];
        float pitch = g_buttonWidth + 2 * g_buttonMargin;
        left[firstApp] += pitch + dividerSpace;
        left[explorer] = icons[firstApp].slotLeft - e.slotLeft;
        right[explorer] = -pitch - left[explorer];
        beforeAppsDivider = e.element;
    } else if (p.appsDivider) {
        std::vector<wux::FrameworkElement> buttons;
        for (size_t i : order) buttons.push_back(icons[i].element);
        beforeAppsDivider = AppsDividerButton(buttons);
        for (size_t i = 0; i < icons.size(); i++) {
            if (icons[i].element == beforeAppsDivider) right[i] += g_dividerSpace;
        }
    }

    bool changed = false;
    for (size_t i = 0; i < icons.size(); i++) {
        Button* b = FindButton(icons[i].element);
        if (!b || (std::fabs(b->extraLeft - left[i]) < 0.5f &&
                   std::fabs(b->extraRight - right[i]) < 0.5f)) {
            continue;
        }
        b->extraLeft = left[i];
        b->extraRight = right[i];
        ApplySpacing(icons[i].element);
        changed = true;
    }
    if (changed) MarkPlatesDirty();
    return {icons[last].element, beforeAppsDivider};
}

// Re-measure the plate around the icons, as if nothing were magnified.
void MeasurePlate(Plate& p) {
    auto row = p.row.get();
    auto panel = p.panel.get();
    if (!row || !panel || !p.root) return;

    // The taskbar it's in, for the pointer hooks. Looked up here, once it's
    // surely in the tree.
    if (!p.frame.get()) {
        if (auto frame = FindTaskbarFrame(row.as<wux::FrameworkElement>())) {
            p.frame = winrt::make_weak(frame);
        }
    }

    auto icons = GetIcons(row);
    if (icons.empty()) {
        for (wux::UIElement el : {wux::UIElement(p.root), wux::UIElement(p.trash),
                                  wux::UIElement(p.divider), wux::UIElement(p.appsDivider)}) {
            if (el) el.Visibility(wux::Visibility::Collapsed);
        }
        return;
    }
    std::sort(icons.begin(), icons.end(),
              [](Icon const& a, Icon const& b) { return a.left < b.left; });

    float minLeft = icons[0].left, maxRight = icons[0].left + icons[0].width;
    float minTop = icons[0].top, maxBottom = icons[0].top + icons[0].height;
    for (auto& icon : icons) {
        minLeft = std::min(minLeft, icon.left);
        maxRight = std::max(maxRight, icon.left + icon.width);
        minTop = std::min(minTop, icon.top);
        maxBottom = std::max(maxBottom, icon.top + icon.height);
    }

    // Horizontally: the buttons are wider than their icons (empty space on
    // each side), so pull the edges in by that much, then add the padding
    // measured from the icons themselves.
    float avgWidth = 0;
    for (auto& icon : icons) avgWidth += icon.width;
    avgWidth /= icons.size();
    float emptyPerSide = std::max(0.0f, (avgWidth - g_iconSize) / 2);
    float padX = g_dockSidePadding - emptyPerSide;
    auto origin = row.TransformToVisual(panel).TransformPoint({0, 0});
    p.baseLeft = origin.X + minLeft - padX;
    p.baseWidth = (maxRight - minLeft) + 2 * padX;

    // Vertically: the dock sits at the bottom of the taskbar and the icons are
    // moved down onto it, since layout centers them in the full-height taskbar.
    float height = g_dockHeight;
    p.top = (float)panel.ActualHeight() - g_dockBottomGap - height;
    float iconCenterY = origin.Y + (minTop + maxBottom) / 2;
    float offsetY = p.top + height / 2 - iconCenterY;

    // A new element's Height is NaN, and any comparison with NaN is false, so
    // check for it explicitly.
    double current = p.root.Height();
    if (std::isnan(current) || std::fabs(current - height) > 0.5) p.root.Height(height);
    p.left = p.width = -1;  // force ApplyPlate to write
    p.root.Visibility(wux::Visibility::Visible);

    // Room between the buttons for the dividers and the Recycle Bin, and File
    // Explorer moved into place.
    auto [beforeTrash, beforeAppsDivider] = LayOutButtons(p, icons);
    p.beforeTrash = winrt::make_weak(beforeTrash);
    p.beforeAppsDivider = beforeAppsDivider ? winrt::make_weak(beforeAppsDivider) : nullptr;
    auto iconOf = [&](wux::FrameworkElement const& el) -> Icon const& {
        for (auto& icon : icons) {
            if (icon.element == el) return icon;
        }
        return icons.back();
    };

    // Where a divider goes: centered in the space after `icon`, which starts
    // at the end of the icon's own space (half the gap past it).
    float centerY = p.top + height / 2;
    auto placeDivider = [&](wuxc::Border const& divider, Icon const& icon) {
        float x = icon.left + icon.width + g_buttonMargin + g_dividerSpace / 2;
        divider.Margin({origin.X + x - 0.5f, centerY - g_iconSize / 2, 0, 0});
        divider.Visibility(wux::Visibility::Visible);
    };

    // The Recycle Bin goes past the last button, after its divider.
    if (p.trash) {
        auto& last = iconOf(beforeTrash);
        p.trashCenter = last.left + last.width + g_buttonMargin + g_dividerSpace + g_trashSlot / 2;
        p.baseWidth += g_trashSpace;

        float trashSize = g_iconSize * kTrashIconScale;
        p.trash.Margin({origin.X + p.trashCenter - trashSize / 2, centerY - trashSize / 2, 0, 0});
        p.trash.Visibility(wux::Visibility::Visible);
        placeDivider(p.divider, last);
        UpdateTrashIcons();
    }

    // The divider after File Explorer. Its space is between buttons, so the
    // plate's width above already includes it.
    if (p.appsDivider) {
        p.appsDivider.Visibility(wux::Visibility::Collapsed);
        if (beforeAppsDivider) placeDivider(p.appsDivider, iconOf(beforeAppsDivider));
    }

    // Re-apply every icon's transform so the new offset and dock bottom take
    // effect, keeping any magnification currently in progress.
    p.offsetY = offsetY;
    p.dockBottom = p.top + height - origin.Y;
    for (auto& icon : icons) ReapplyButton(icon.element);
}

// Position the plate, widened by `extra` px in all, `extraLeft` of it to the
// left.
void ApplyPlate(Plate& p, float extraLeft, float extra) {
    if (!p.root) return;
    float left = p.baseLeft - extraLeft;
    float width = p.baseWidth + extra;
    if (std::fabs(left - p.left) > 0.25f || std::fabs(width - p.width) > 0.25f) {
        p.root.Margin({left, p.top, 0, 0});
        p.root.Width(width);
        p.left = left;
        p.width = width;
    }
}

void RemovePlates() {
    for (auto& p : *g_plates) {
        p.rowSizeChanged.revoke();
        p.panelSizeChanged.revoke();
        p.panelThemeChanged.revoke();
        if (p.blurHost) {
            try { wuxh::ElementCompositionPreview::SetElementChildVisual(p.blurHost, nullptr); }
            catch (...) {}
        }
        p.trashTapped.revoke();
        p.trashRightTapped.revoke();
        p.trashDragEnter.revoke();
        p.trashDragOver.revoke();
        p.trashDrop.revoke();
        auto panel = p.panel.get();
        if (!panel) continue;
        for (wux::UIElement el : {wux::UIElement(p.root), wux::UIElement(p.trash),
                                  wux::UIElement(p.divider), wux::UIElement(p.appsDivider)}) {
            uint32_t index;
            if (el && panel.Children().IndexOf(el, index)) panel.Children().RemoveAt(index);
        }
    }
    g_plates->clear();
}

// ---- Recycle Bin ----

// Raw access to a WriteableBitmap's pixels (IBufferByteAccess).
MIDL_INTERFACE("905a0fef-bc53-11df-8c49-001e4fc686da")
IDockBufferByteAccess : public IUnknown {
public:
    virtual HRESULT STDMETHODCALLTYPE Buffer(BYTE** value) = 0;
};
__CRT_UUID_DECL(IDockBufferByteAccess, 0x905a0fef, 0xbc53, 0x11df, 0x8c, 0x49, 0x00, 0x1e, 0x4f,
                0xc6, 0x86, 0xda)

// Windows' own Recycle Bin icon, `px` pixels square.
wuxm::ImageSource LoadStockTrashIcon(bool full, int px) {
    SHSTOCKICONINFO info{sizeof(info)};
    HICON icon = nullptr;
    if (FAILED(SHGetStockIconInfo(full ? SIID_RECYCLERFULL : SIID_RECYCLER, SHGSI_ICONLOCATION,
                                  &info)) ||
        SHDefExtractIconW(info.szPath, info.iIcon, 0, &icon, nullptr, px) != S_OK || !icon) {
        Wh_Log(L"[trash] couldn't load Windows' icon");
        return nullptr;
    }

    // Its pixels, top row first, in the BGRA order XAML uses.
    ICONINFO ii{};
    BITMAP bm{};
    std::vector<BYTE> pixels;
    if (GetIconInfo(icon, &ii)) {
        if (ii.hbmColor && GetObject(ii.hbmColor, sizeof(bm), &bm)) {
            BITMAPINFO bi{};
            bi.bmiHeader = {sizeof(BITMAPINFOHEADER), bm.bmWidth, -bm.bmHeight, 1, 32, BI_RGB};
            pixels.resize((size_t)bm.bmWidth * bm.bmHeight * 4);
            HDC dc = GetDC(nullptr);
            if (GetDIBits(dc, ii.hbmColor, 0, bm.bmHeight, pixels.data(), &bi, DIB_RGB_COLORS) !=
                bm.bmHeight) {
                pixels.clear();
            }
            ReleaseDC(nullptr, dc);
        }
        if (ii.hbmColor) DeleteObject(ii.hbmColor);
        if (ii.hbmMask) DeleteObject(ii.hbmMask);
    }
    DestroyIcon(icon);
    if (pixels.empty()) return nullptr;

    // XAML wants the colors premultiplied by their transparency.
    for (size_t i = 0; i < pixels.size(); i += 4) {
        BYTE a = pixels[i + 3];
        for (int c = 0; c < 3; c++) pixels[i + c] = (BYTE)(pixels[i + c] * a / 255);
    }
    wuxm::Imaging::WriteableBitmap bitmap(bm.bmWidth, bm.bmHeight);
    BYTE* data = nullptr;
    winrt::check_hresult(bitmap.PixelBuffer().as<IDockBufferByteAccess>()->Buffer(&data));
    memcpy(data, pixels.data(), pixels.size());
    bitmap.Invalidate();
    return bitmap;
}

// The icons, loaded once and shared by every taskbar's Recycle Bin.
[[clang::no_destroy]] wuxm::ImageSource g_trashIcons[2] = {nullptr, nullptr};

// Windows' icon for the Recycle Bin's state, loaded at the size it's shown at
// fully magnified.
wuxm::ImageSource TrashIcon(bool full, wux::UIElement const& el) {
    auto& icon = g_trashIcons[full];
    if (icon) return icon;
    double dpiScale = 1;
    try {
        if (auto root = el.XamlRoot()) dpiScale = root.RasterizationScale();
    } catch (...) {}
    return icon = LoadStockTrashIcon(
               full, (int)std::ceil(g_iconLoadSize * kTrashIconScale * dpiScale));
}

// Whether the Recycle Bin has anything in it: -1 = not known yet, 0 = empty,
// 1 = full. Checked whenever Windows reports a change to it, on a thread pool
// thread since it can take a moment with many drives.
std::atomic<int> g_trashFull = -1;
std::atomic<bool> g_trashChecking = false;
PTP_WORK g_trashWork = nullptr;
ULONG g_trashNotify = 0;  // the SHChangeNotifyRegister registration

void CALLBACK CheckRecycleBin(PTP_CALLBACK_INSTANCE, PVOID, PTP_WORK) {
    HRESULT co = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    SHQUERYRBINFO info{sizeof(info)};
    if (SUCCEEDED(SHQueryRecycleBinW(nullptr, &info))) g_trashFull = info.i64NumItems > 0;
    if (SUCCEEDED(co)) CoUninitialize();
    g_trashChecking = false;
    if (HWND w = g_modWindow) PostMessage(w, kTrashCheckedMessage, 0, 0);  // show it
}

void CheckRecycleBinSoon() {
    if (g_trashWork && !g_trashChecking.exchange(true)) SubmitThreadpoolWork(g_trashWork);
}

// Shows each Recycle Bin's icon for the latest known state.
void UpdateTrashIcons() {
    int full = g_trashFull;
    for (auto& p : *g_plates) {
        if (!p.trashImage || p.trashState == full) continue;
        p.trashState = full;
        try {
            p.trashImage.Source(TrashIcon(full == 1, p.trashImage));
        } catch (...) {
            Wh_Log(L"[trash] icon failed: 0x%08X", winrt::to_hresult());
        }
    }
}

// Asks Windows to report changes to the Recycle Bin to the mod's window,
// which then checks it again (see ModWindowProc).
void StartTrash() {
    if (!g_trashWork) g_trashWork = CreateThreadpoolWork(CheckRecycleBin, nullptr, nullptr);
    HWND w = EnsureModWindow();  // first, as it's sent the result
    CheckRecycleBinSoon();
    if (g_trashNotify) return;
    PIDLIST_ABSOLUTE bin;
    if (!w || FAILED(SHGetFolderLocation(nullptr, CSIDL_BITBUCKET, nullptr, 0, &bin))) return;
    SHChangeNotifyEntry entry{bin, TRUE};
    g_trashNotify = SHChangeNotifyRegister(w, SHCNRF_ShellLevel, SHCNE_ALLEVENTS,
                                           kTrashChangedMessage, 1, &entry);
    CoTaskMemFree(bin);
    if (!g_trashNotify) Wh_Log(L"[trash] can't watch the Recycle Bin for changes");
}

// Stops watching it and lets go of the icons. The check that may still be
// running is waited for in Wh_ModBeforeUninit, off the taskbar's thread.
void StopTrash() {
    if (g_trashNotify) {
        SHChangeNotifyDeregister(g_trashNotify);
        g_trashNotify = 0;
    }
    g_trashIcons[0] = g_trashIcons[1] = nullptr;
}

void OpenRecycleBin() {
    ShellExecuteW(nullptr, L"open", L"shell:RecycleBinFolder", nullptr, nullptr, SW_SHOWNORMAL);
}

// Moves files to the Recycle Bin, so they can be restored; Windows warns
// first if one is too big for it and would be deleted for good. `paths` is a
// list of paths, each ending in a null character. Run as a shell job.
void RecycleFiles(std::wstring const& paths) {
    SHFILEOPSTRUCTW op{};
    op.wFunc = FO_DELETE;
    op.pFrom = paths.c_str();  // its own final null ends the list
    op.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_WANTNUKEWARNING;
    if (int error = SHFileOperationW(&op)) Wh_Log(L"[trash] recycling failed: %d", error);
    CheckRecycleBinSoon();
}

// Asks first, like emptying it anywhere else in Windows. Run as a shell job.
void EmptyRecycleBin() {
    SHEmptyRecycleBinW(nullptr, nullptr, 0);
    CheckRecycleBinSoon();
}

// Right-click: Open, and Empty Recycle Bin (unavailable when it's empty).
void ShowTrashMenu(wux::FrameworkElement const& target) {
    wuxc::MenuFlyoutItem open;
    open.Text(L"Open");
    open.Click([](wf::IInspectable const&, wux::RoutedEventArgs const&) { OpenRecycleBin(); });
    wuxc::MenuFlyoutItem empty;
    empty.Text(L"Empty Recycle Bin");
    empty.IsEnabled(g_trashFull != 0);
    empty.Click([](wf::IInspectable const&, wux::RoutedEventArgs const&) {
        QueueShellJob(EmptyRecycleBin);
    });
    wuxc::MenuFlyout menu;
    menu.Items().Append(open);
    menu.Items().Append(empty);
    menu.ShowAt(target);
}

// Files dragged over the Recycle Bin: offer to move them there.
void AcceptTrashDrag(wux::DragEventArgs const& e) {
    if (!e.DataView().Contains(wadt::StandardDataFormats::StorageItems())) return;
    e.AcceptedOperation(wadt::DataPackageOperation::Move);
    if (auto ui = e.DragUIOverride()) ui.Caption(L"Move to Recycle Bin");
    e.Handled(true);
}

// Files dropped on the Recycle Bin: read the paths and recycle them in a shell
// job. The drop itself finishes right away, because the source window waits
// for it and is also where the paths are read from. It reports "no operation"
// so the source doesn't delete the files itself.
void OnTrashDrop(wux::DragEventArgs const& e) {
    e.Handled(true);
    e.AcceptedOperation(wadt::DataPackageOperation::None);
    if (!e.DataView().Contains(wadt::StandardDataFormats::StorageItems())) return;
    QueueShellJob([items = winrt::make_agile(e.DataView().GetStorageItemsAsync())] {
        std::wstring paths;
        try {
            for (auto const& item : items.get().get()) {
                auto path = item.Path();
                if (path.empty()) continue;  // not a file on disk
                paths.append(path.c_str(), path.size());
                paths.push_back(L'\0');
            }
        } catch (...) {
            Wh_Log(L"[trash] reading the dropped files failed: 0x%08X", winrt::to_hresult());
            return;
        }
        if (!paths.empty()) RecycleFiles(paths);
    });
}

void HookUpTrash(Plate& p) {
    p.trash.AllowDrop(true);
    p.trashTapped = p.trash.Tapped(
        winrt::auto_revoke, [](wf::IInspectable const&, wuxi::TappedRoutedEventArgs const& e) {
            e.Handled(true);
            OpenRecycleBin();
        });
    p.trashRightTapped = p.trash.RightTapped(
        winrt::auto_revoke,
        [](wf::IInspectable const& sender, wuxi::RightTappedRoutedEventArgs const& e) {
            e.Handled(true);
            try { ShowTrashMenu(sender.as<wux::FrameworkElement>()); } catch (...) {
                Wh_Log(L"[trash] menu failed: 0x%08X", winrt::to_hresult());
            }
        });
    auto accept = [](wf::IInspectable const&, wux::DragEventArgs const& e) {
        try { AcceptTrashDrag(e); } catch (...) {}
    };
    p.trashDragEnter = p.trash.DragEnter(winrt::auto_revoke, accept);
    p.trashDragOver = p.trash.DragOver(winrt::auto_revoke, accept);
    p.trashDrop = p.trash.Drop(
        winrt::auto_revoke, [](wf::IInspectable const&, wux::DragEventArgs const& e) {
            try { OnTrashDrop(e); } catch (...) {
                Wh_Log(L"[trash] drop failed: 0x%08X", winrt::to_hresult());
            }
        });
}

// Magnifies the Recycle Bin like a button (growing upward from its bottom
// edge) and shifts it and the divider sideways.
void SetTrashScale(Plate& p, float s, float tx, float dividerTx) {
    if (!p.trash) return;
    auto visual = wuxh::ElementCompositionPreview::GetElementVisual(p.trash);
    // Its pivot is on the same line as the buttons': the bottom of an icon.
    float size = g_iconSize * kTrashIconScale;
    visual.CenterPoint({size / 2, size / 2 + g_iconSize / 2, 0});
    visual.Scale({s, s, 1});
    wuxh::ElementCompositionPreview::SetIsTranslationEnabled(p.trash, true);
    visual.Properties().InsertVector3(L"Translation", {tx, 0, 0});
    auto divider = wuxh::ElementCompositionPreview::GetElementVisual(p.divider);
    wuxh::ElementCompositionPreview::SetIsTranslationEnabled(p.divider, true);
    divider.Properties().InsertVector3(L"Translation", {dividerTx, 0, 0});
}

// ---- Running indicators ----
// The indicator is part of its button, so it would grow and move with it.
// PlaceIndicator keeps it at normal size under the icon, just above the dock's
// bottom edge.

struct Indicator {
    winrt::weak_ref<wux::FrameworkElement> element;
    winrt::weak_ref<wux::FrameworkElement> button;
    winrt::weak_ref<wux::FrameworkElement> dot;  // our replacement dot, if any
    wux::FrameworkElement::SizeChanged_revoker sizeChanged;
    wux::FrameworkElement::SizeChanged_revoker dotSizeChanged;
};

[[clang::no_destroy]] std::optional<std::list<Indicator>> g_indicators{std::in_place};

void PlaceIndicator(wux::FrameworkElement const& button, float s) {
    wux::FrameworkElement el{nullptr};
    for (auto& i : *g_indicators) {
        if (i.button.get() == button) {
            el = i.dot.get();
            if (!el) el = i.element.get();
            break;
        }
    }
    if (!el) return;
    auto visual = wuxh::ElementCompositionPreview::GetElementVisual(el);
    wuxh::ElementCompositionPreview::SetIsTranslationEnabled(el, true);

    auto reset = [&] {
        visual.Scale({1, 1, 1});
        visual.Properties().InsertVector3(L"Translation", {0, 0, 0});
    };
    Plate* p = GetRowPlate(wuxm::VisualTreeHelper::GetParent(button));
    if (!p || s <= 0) return reset();

    // The indicator's vertical center within the button, as laid out.
    float w = (float)el.ActualWidth(), h = (float)el.ActualHeight();
    float centerY = h / 2;
    wux::DependencyObject current = el;
    while (current && current != button) {
        if (auto ui = current.try_as<wux::UIElement>()) centerY += ui.ActualOffset().y;
        current = wuxm::VisualTreeHelper::GetParent(current);
    }
    if (!current) return reset();  // not inside this button after all

    // Where it should be: just above the dock's bottom edge.
    auto slot = wuxc::Primitives::LayoutInformation::GetLayoutSlot(button);
    float buttonTop = slot.Y + (float)button.Margin().Top;
    float inset = std::max(2.0f, std::round(g_iconSize / 10));
    float targetY = p->dockBottom - buttonTop - inset - h / 2;

    // The button scales by s around its pivot, then moves down by offsetY.
    // Scale the indicator by 1/s around its own center to cancel the growth,
    // and move it so that after the button's transform it lands on targetY.
    float pivotY = ButtonPivotY(button);
    float ty = (targetY - p->offsetY - pivotY) / s + pivotY - centerY;
    visual.CenterPoint({w / 2, h / 2, 0});
    visual.Scale({1 / s, 1 / s, 1});
    visual.Properties().InsertVector3(L"Translation", {0, ty, 0});
}

void TrackIndicator(wux::FrameworkElement const& el, wux::FrameworkElement const& button) {
    for (auto& i : *g_indicators) {
        if (i.element.get() == el) return;
    }
    auto& i = g_indicators->emplace_back();
    i.element = winrt::make_weak(el);
    i.button = winrt::make_weak(button);
    // Laid out for the first time, or wider for the active app: re-place it.
    i.sizeChanged = el.SizeChanged(
        winrt::auto_revoke, [weakButton = i.button](wf::IInspectable const&,
                                                    wux::SizeChangedEventArgs const&) {
            try {
                if (auto b = weakButton.get()) ReapplyButton(b);
            } catch (...) {}
        });
}

void RestoreIndicators() {
    for (auto& i : *g_indicators) {
        i.sizeChanged.revoke();
        i.dotSizeChanged.revoke();
        if (auto el = i.element.get()) {
            try {
                auto visual = wuxh::ElementCompositionPreview::GetElementVisual(el);
                visual.Scale({1, 1, 1});
                visual.Properties().InsertVector3(L"Translation", {0, 0, 0});
                wuxh::ElementCompositionPreview::SetIsTranslationEnabled(el, false);
            } catch (...) {}
        }
    }
    g_indicators->clear();
}

// ---- Running indicator style (dots, from Taskbar Styler) ----
// The taskbar's indicator is clipped to nothing and a 4px dot is drawn instead:
// light (#D6D6D6) for the focused app, dim (#8A8A8A) for other open apps. The
// dot is added from the per-frame scan, not from the taskbar's hooks.

bool g_scanningInFrame = false;

struct StyledIndicator {
    winrt::weak_ref<wux::FrameworkElement> element;  // the taskbar's own indicator
    wuxs::Ellipse dot{nullptr};
    winrt::weak_ref<wuxc::Panel> panel;
    wux::VisualStateGroup group{nullptr};
    winrt::event_token stateToken{};
    wf::IInspectable originalClip{nullptr};
    int64_t clipToken = 0;
};

[[clang::no_destroy]] std::optional<std::list<StyledIndicator>> g_styledIndicators{std::in_place};

void UpdateDot(StyledIndicator& si) {
    using winrt::Windows::UI::Color;
    auto state = si.group.CurrentState();
    winrt::hstring name = state ? state.Name() : winrt::hstring{};
    if (name == L"ActiveRunningIndicator") {
        si.dot.Fill(wuxm::SolidColorBrush(Color{255, 0xD6, 0xD6, 0xD6}));
        si.dot.Visibility(wux::Visibility::Visible);
    } else if (name == L"InactiveRunningIndicator") {
        si.dot.Fill(wuxm::SolidColorBrush(Color{255, 0x8A, 0x8A, 0x8A}));
        si.dot.Visibility(wux::Visibility::Visible);
    } else {
        si.dot.Visibility(wux::Visibility::Collapsed);
    }
}

void StyleIndicator(wux::FrameworkElement const& el, wux::FrameworkElement const& button) {
    if (!g_scanningInFrame) return;  // this changes the tree: frame scan only
    for (auto& s : *g_styledIndicators) {
        if (s.element.get() == el) return;
    }
    auto panel = wuxm::VisualTreeHelper::GetParent(el).try_as<wuxc::Panel>();
    if (!panel) return;

    // The visual state group lives on the button's template root.
    wux::VisualStateGroup group{nullptr};
    wux::DependencyObject current = el;
    while (current && !group) {
        if (auto fe = current.try_as<wux::FrameworkElement>()) {
            if (auto groups = wux::VisualStateManager::GetVisualStateGroups(fe)) {
                for (auto g : groups) {
                    if (g.Name() == L"RunningIndicatorStates") {
                        group = g;
                        break;
                    }
                }
            }
        }
        if (current == button) break;
        current = wuxm::VisualTreeHelper::GetParent(current);
    }
    if (!group) return;

    // Our dot: same place in the grid as the taskbar's indicator.
    wuxs::Ellipse dot;
    dot.Width(4);
    dot.Height(4);
    dot.IsHitTestVisible(false);
    dot.HorizontalAlignment(el.HorizontalAlignment());
    dot.VerticalAlignment(el.VerticalAlignment());
    dot.Margin(el.Margin());
    dot.Visibility(wux::Visibility::Collapsed);
    if (panel.try_as<wuxc::Grid>()) {
        wuxc::Grid::SetRow(dot, wuxc::Grid::GetRow(el));
        wuxc::Grid::SetColumn(dot, wuxc::Grid::GetColumn(el));
        wuxc::Grid::SetRowSpan(dot, wuxc::Grid::GetRowSpan(el));
        wuxc::Grid::SetColumnSpan(dot, wuxc::Grid::GetColumnSpan(el));
    }
    uint32_t index = 0;
    if (panel.Children().IndexOf(el, index)) panel.Children().InsertAt(index + 1, dot);
    else panel.Children().Append(dot);

    auto& si = g_styledIndicators->emplace_back();
    si.element = winrt::make_weak(el);
    si.dot = dot;
    si.panel = winrt::make_weak(panel);
    si.group = group;
    si.originalClip = el.ReadLocalValue(wux::UIElement::ClipProperty());

    // Hide the taskbar's own indicator. Its states don't set Clip.
    wuxm::RectangleGeometry nothing;
    nothing.Rect(wf::Rect{0, 0, 0, 0});
    el.Clip(nothing);

    // If anything puts a real clip back, empty it again.
    si.clipToken = el.RegisterPropertyChangedCallback(
        wux::UIElement::ClipProperty(),
        [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
            try {
                if (g_unloading) return;
                auto ui = sender.try_as<wux::UIElement>();
                if (!ui) return;
                auto current = ui.Clip();
                if (current && current.Rect().Width == 0 && current.Rect().Height == 0) return;
                wuxm::RectangleGeometry empty;
                empty.Rect(wf::Rect{0, 0, 0, 0});
                ui.Clip(empty);
            } catch (...) {}
        });

    // Also shrink its composition visual to nothing, which XAML states can't undo.
    wuxh::ElementCompositionPreview::GetElementVisual(el).Scale({0, 0, 1});

    si.stateToken = group.CurrentStateChanged(
        [weakEl = si.element](wf::IInspectable const&, wux::VisualStateChangedEventArgs const&) {
            try {
                auto indicator = weakEl.get();
                if (!indicator || !g_styledIndicators) return;
                for (auto& s : *g_styledIndicators) {
                    if (s.element.get() == indicator) {
                        UpdateDot(s);
                        break;
                    }
                }
            } catch (...) {}
        });
    UpdateDot(si);

    // Let PlaceIndicator move and scale the dot instead of the old indicator.
    for (auto& i : *g_indicators) {
        if (i.element.get() != el) continue;
        wux::FrameworkElement dotElement = dot;
        i.dot = winrt::make_weak(dotElement);
        i.dotSizeChanged = dotElement.SizeChanged(
            winrt::auto_revoke, [weakButton = i.button](wf::IInspectable const&,
                                                        wux::SizeChangedEventArgs const&) {
                try {
                    if (auto b = weakButton.get()) ReapplyButton(b);
                } catch (...) {}
            });
        break;
    }
    ReapplyButton(button);
}

void RestoreStyledIndicators() {
    for (auto& si : *g_styledIndicators) {
        try {
            if (si.group && si.stateToken.value) si.group.CurrentStateChanged(si.stateToken);
        } catch (...) {}
        try {
            auto panel = si.panel.get();
            uint32_t index;
            if (panel && si.dot && panel.Children().IndexOf(si.dot, index)) {
                panel.Children().RemoveAt(index);
            }
        } catch (...) {}
        if (auto el = si.element.get()) {
            try {
                if (si.clipToken) {
                    el.UnregisterPropertyChangedCallback(wux::UIElement::ClipProperty(),
                                                         si.clipToken);
                }
                RestoreLocalValue(el, wux::UIElement::ClipProperty(), si.originalClip);
            } catch (...) {}
        }
    }
    g_styledIndicators->clear();
}

// (Re)builds the list of icons in `parent`. Icons already in the list keep
// their size so a rebuild mid-hover doesn't jump; icons that dropped out reset
// to normal size.
void BuildRow(wux::UIElement const& parent) {
    std::vector<RowItem> old = std::move(g_row);
    Plate* oldPlate = GetRowPlate(g_rowParent.get());
    if (g_rowParent.get() != parent) g_maxGrowth = g_lastGrowth = 0;  // another taskbar
    g_row.clear();
    g_rowParent = nullptr;

    if (parent) {
        for (auto& icon : GetIcons(parent)) {
            // The margins change how far apart buttons sit, so spread by the
            // space each one actually takes up rather than its own width.
            float pitch = std::max(1.0f, icon.width + 2 * g_buttonMargin);
            RowItem item{winrt::make_weak(icon.element), icon.left + icon.width / 2, pitch};
            for (auto& o : old) {
                if (o.element.get() == icon.element) {
                    item.scale = o.scale;
                    item.shift = o.shift;
                    o.element = nullptr;  // still in the row; don't reset it below
                    break;
                }
            }
            g_row.push_back(item);
        }
        // Left to right, so the spreading below shifts icons in the right order.
        std::sort(g_row.begin(), g_row.end(),
                  [](RowItem const& a, RowItem const& b) { return a.center < b.center; });
        g_rowParent = winrt::make_weak(parent);
        Plate* p = GetRowPlate(parent);

        // The Recycle Bin comes last.
        if (p && p->trash && !g_row.empty() &&
            p->trash.Visibility() == wux::Visibility::Visible) {
            RowItem item{nullptr, p->trashCenter, g_trashSlot};
            item.trash = true;
            for (auto& o : old) {
                if (o.trash && oldPlate == p) {
                    item.scale = o.scale;
                    item.shift = o.shift;
                    o.trash = false;  // still in the row; don't reset it below
                }
            }
            g_row.push_back(item);
        }
    }

    for (auto& o : old) {
        if (auto icon = o.element.get()) SetScale(icon, 1.0f);
        if (o.trash && oldPlate) SetTrashScale(*oldPlate, 1.0f, 0, 0);
    }
    if (oldPlate && oldPlate != GetRowPlate(parent)) SetAppsDividerShift(*oldPlate, 0);
}

// ---- Once-per-frame update ----
// CompositionTarget::Rendering fires once per screen refresh. We only
// subscribe while icons are moving toward their target size.

winrt::event_token g_frameToken{};
bool g_frameRunning = false;
std::chrono::steady_clock::time_point g_lastFrame;

void ScanTaskbars();

void StopFrames() {
    if (!g_frameRunning) return;
    wuxm::CompositionTarget::Rendering(g_frameToken);
    g_frameRunning = false;
}

void OnFrame() {
    auto now = std::chrono::steady_clock::now();
    float dt = std::chrono::duration<float>(now - g_lastFrame).count();
    g_lastFrame = now;
    if (dt > 0.1f) dt = 0.1f;

    // How far to move toward the target this frame. animationMs is roughly
    // the time to get (almost) all the way there.
    float alpha = 1.0f;
    if (g_animationMs > 0) {
        float tau = g_animationMs / 1000.0f / 3.0f;
        alpha = 1.0f - std::exp(-dt / tau);
    }

    // 0. After buttons change: find buttons the hooks missed, create plates and
    //    re-measure. Done here because the taskbar doesn't tolerate tree changes
    //    while it's updating a button.
    if (g_platesDirtyFrames > 0) {
        g_platesDirtyFrames--;
        g_scanningInFrame = true;
        try { ScanTaskbars(); } catch (...) {
            Wh_Log(L"ScanTaskbars failed: 0x%08X", winrt::to_hresult());
        }
        g_scanningInFrame = false;
        for (auto& b : *g_buttons) {
            if (auto el = b.element.get()) {
                try { EnsurePlate(el); } catch (...) {
                    Wh_Log(L"EnsurePlate failed: 0x%08X", winrt::to_hresult());
                }
            }
        }
        for (auto& p : *g_plates) MeasurePlate(p);
        ScheduleOverWindows(false);  // the taskbar may have changed size
    }

    // 0b. Re-read where the row's icons are, in their current order, so the
    //     magnification follows apps that opened, closed or were dragged to
    //     a new spot. Sizes in progress are kept.
    if (auto rowParent = g_rowParent.get()) BuildRow(rowParent);

    // 1. Move each icon's scale toward its target.
    bool settled = g_platesDirtyFrames == 0;
    std::vector<float> scales(g_row.size(), 1.0f);
    for (size_t i = 0; i < g_row.size(); i++) {
        auto& item = g_row[i];

        float target = 1.0f;
        if (g_pointerOver) {
            float d = std::fabs(g_pointerX - item.center);
            if (d < g_radius) {
                // Cosine falloff: full size under the pointer, normal at the radius.
                float k = (std::cos(d / g_radius * 3.14159265f) + 1.0f) / 2.0f;
                target = 1.0f + (g_scale - 1.0f) * k;
            }
        }

        float s = item.scale + (target - item.scale) * alpha;
        if (std::fabs(target - s) < 0.001f) {
            s = target;
        } else {
            settled = false;
        }
        scales[i] = s;
    }

    // While the pointer is on the dock or icons are still magnified, the
    // taskbar isn't clipped (see ClipTaskbars).
    bool expanded = g_pointerOver;
    for (float scale : scales) expanded |= scale > 1.0f;
    if (expanded != g_dockExpanded) {
        g_dockExpanded = expanded;
        ScheduleOverWindows(false);
    }

    // 2. Spread: each icon is pushed right by the extra width of the icons
    //    before it, then the row is pulled back left by growLeft. As on a Mac,
    //    one end of the dock stays put: the left end when the pointer is right
    //    of the middle, and the other way around.
    float total = 0;
    for (size_t i = 0; i < g_row.size(); i++) {
        total += (scales[i] - 1.0f) * g_row[i].width;
    }
    if (g_pointerOver) {
        if (!g_row.empty()) {
            float middle = (g_row.front().center - g_row.front().width / 2 +
                            g_row.back().center + g_row.back().width / 2) / 2;
            g_anchorLeftEnd = g_pointerX > middle;
        }
        g_maxGrowth = std::max(g_maxGrowth, total);
    } else if (g_lastGrowth > 0) {
        // Left the dock: shrink back keeping the same shape, so neither end
        // jumps.
        g_maxGrowth *= total / g_lastGrowth;
    } else {
        g_maxGrowth = total;
    }
    g_lastGrowth = total;
    float growLeft = g_anchorLeftEnd ? g_maxGrowth / 2 : total - g_maxGrowth / 2;

    auto rowParent = g_rowParent.get();
    Plate* plate = GetRowPlate(rowParent);
    auto beforeAppsDivider = plate ? plate->beforeAppsDivider.get() : nullptr;
    float appsDividerShift = 0;
    float before = 0;
    for (size_t i = 0; i < g_row.size(); i++) {
        auto& item = g_row[i];
        float extra = (scales[i] - 1.0f) * item.width;
        float shift = before + extra / 2 - growLeft;
        float gapShift = before - growLeft;  // of the space just before this item
        before += extra;
        // The apps divider sits in the space just after its button.
        if (beforeAppsDivider && item.element.get() == beforeAppsDivider) {
            appsDividerShift = before - growLeft;
        }

        if (item.trash) {
            // Its divider sits in the space just before it.
            if (plate && (scales[i] != item.scale || std::fabs(shift - item.shift) > 0.01f)) {
                SetTrashScale(*plate, scales[i], shift, gapShift);
                item.scale = scales[i];
                item.shift = shift;
            }
            continue;
        }

        auto icon = item.element.get();
        if (!icon) continue;
        if (scales[i] != item.scale || std::fabs(shift - item.shift) > 0.01f) {
            SetScale(icon, scales[i], shift);
            item.scale = scales[i];
            item.shift = shift;
        }
    }
    if (plate) SetAppsDividerShift(*plate, appsDividerShift);

    // 3. Widen the plate under the current row the same way.
    for (auto& p : *g_plates) {
        bool current = rowParent && p.row.get() == rowParent;
        ApplyPlate(p, current ? growLeft : 0, current ? total : 0);
    }

    if (settled) StopFrames();
}

void StartFrames() {
    if (g_frameRunning) return;
    g_lastFrame = std::chrono::steady_clock::now();
    g_frameToken = wuxm::CompositionTarget::Rendering(
        [](wf::IInspectable const&, wf::IInspectable const&) {
            try {
                OnFrame();
            } catch (...) {
                Wh_Log(L"OnFrame error: 0x%08X %s", winrt::to_hresult(),
                       winrt::to_message().c_str());
                StopFrames();
            }
        });
    g_frameRunning = true;
}

// ---- Taskbar buttons ----

Button& OnButtonAdded(wux::FrameworkElement const& el) {
    for (auto& b : *g_buttons) {
        if (b.element.get() == el) return b;
    }
    auto& b = g_buttons->emplace_back();
    b.element = winrt::make_weak(el);
    b.originalMargin = el.ReadLocalValue(wux::FrameworkElement::MarginProperty());
    // A button for a newly opened app is still being set up when we see it;
    // if the taskbar sets its own margin afterwards, put the dock's back.
    b.marginToken = el.RegisterPropertyChangedCallback(
        wux::FrameworkElement::MarginProperty(),
        [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
            try {
                if (auto fe = sender.try_as<wux::FrameworkElement>()) ApplySpacing(fe);
            } catch (...) {}
        });
    // It's also laid out (or resized) later than the plates' few-frame
    // re-measure; re-measure again when it is, so it gets moved onto the dock.
    b.sizeChanged = el.SizeChanged(
        winrt::auto_revoke,
        [](wf::IInspectable const&, wux::SizeChangedEventArgs const&) { MarkPlatesDirty(); });
    ApplySpacing(el);
    MarkPlatesDirty();  // the plate is created on the next frame
    return b;
}

// Gives the button's template root a minimum width so bigger icons aren't cut
// off (the taskbar sizes buttons for the stock 24px icon).
void ApplyButtonWidth(Button& b, wux::FrameworkElement const& button) {
    auto root = b.root.get();
    if (!root) {
        if (wuxm::VisualTreeHelper::GetChildrenCount(button) == 0) return;  // no template yet
        root = wuxm::VisualTreeHelper::GetChild(button, 0).try_as<wux::FrameworkElement>();
        if (!root) return;
        b.root = winrt::make_weak(root);
        b.originalRootMinWidth = root.ReadLocalValue(wux::FrameworkElement::MinWidthProperty());
    }
    if (root.MinWidth() != g_buttonWidth) root.MinWidth(g_buttonWidth);
}

// Widens the first column of the app button's "IconPanel" grid, which the
// taskbar sizes for the stock icon (see UpdateIconColumnDefinition), to fill
// the button.
void ApplyIconColumn(Button& b) {
    auto root = b.root.get();
    auto grid = root ? root.try_as<wuxc::Grid>() : nullptr;
    if (!grid) return;
    auto columns = grid.ColumnDefinitions();
    if (columns.Size() == 0) return;
    auto column = columns.GetAt(0);
    auto width = column.Width();
    if (width.GridUnitType != wux::GridUnitType::Pixel) return;

    // A value we didn't set is the taskbar's own (it sets it again on updates),
    // kept to put back on unload.
    if (width.Value != b.appliedIconColumn) b.originalIconColumn = width.Value;
    auto padding = grid.Padding();
    double target = g_buttonWidth - padding.Left - padding.Right;
    if (width.Value != target) column.Width({target, wux::GridUnitType::Pixel});
    b.appliedIconColumn = target;
}

// Undoes OnButtonAdded for one button.
void ReleaseButton(Button& b) {
    b.sizeChanged.revoke();
    auto el = b.element.get();
    if (!el) return;
    if (b.marginToken) {
        el.UnregisterPropertyChangedCallback(wux::FrameworkElement::MarginProperty(),
                                             b.marginToken);
        b.marginToken = 0;
    }
    RestoreLocalValue(el, wux::FrameworkElement::MarginProperty(), b.originalMargin);

    // Give the button's tooltip back its own placement (see PlaceTooltip).
    RestoreTooltip(el);

    if (auto root = b.root.get()) {
        if (b.originalIconColumn > 0) {
            if (auto grid = root.try_as<wuxc::Grid>(); grid && grid.ColumnDefinitions().Size()) {
                auto column = grid.ColumnDefinitions().GetAt(0);
                if (column.Width().Value == b.appliedIconColumn) {
                    column.Width({b.originalIconColumn, wux::GridUnitType::Pixel});
                }
            }
        }
        RestoreLocalValue(root, wux::FrameworkElement::MinWidthProperty(),
                          b.originalRootMinWidth);
    }
}

// ---- Start button ----
// With "Start button" off, the Start button is collapsed, and collapsed again
// if the taskbar changes its visibility.

struct StartButton {
    winrt::weak_ref<wux::FrameworkElement> element;
    wux::Visibility originalVisibility = wux::Visibility::Visible;
    int64_t visibilityToken = 0;
};

std::vector<StartButton> g_startButtons;

bool IsStartButton(wux::FrameworkElement const& el) {
    return winrt::get_class_name(el) == L"Taskbar.ExperienceToggleButton" &&
           wux::Automation::AutomationProperties::GetAutomationId(el) == L"StartButton";
}

void HandleStartButton(wux::FrameworkElement const& el) {
    if (g_showStart) return;
    if (!IsStartButton(el)) return;
    g_startButtons.erase(std::remove_if(g_startButtons.begin(), g_startButtons.end(),
                                        [](StartButton& s) { return !s.element.get(); }),
                         g_startButtons.end());
    for (auto& s : g_startButtons) {
        if (s.element.get() == el) return;
    }
    auto& s = g_startButtons.emplace_back();
    s.element = winrt::make_weak(el);
    s.originalVisibility = el.Visibility();
    s.visibilityToken = el.RegisterPropertyChangedCallback(
        wux::UIElement::VisibilityProperty(),
        [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
            try {
                if (g_showStart) return;
                if (auto ui = sender.try_as<wux::UIElement>()) {
                    if (ui.Visibility() != wux::Visibility::Collapsed) {
                        ui.Visibility(wux::Visibility::Collapsed);
                    }
                }
            } catch (...) {}
        });
    el.Visibility(wux::Visibility::Collapsed);
}

void RestoreStartButtons() {
    for (auto& s : g_startButtons) {
        auto el = s.element.get();
        if (!el) continue;
        try {
            el.UnregisterPropertyChangedCallback(wux::UIElement::VisibilityProperty(),
                                                 s.visibilityToken);
            el.Visibility(s.originalVisibility);
        } catch (...) {}
    }
    g_startButtons.clear();
}

// Everything the mod changes in one taskbar button (an app, Start, Task
// View...): its spacing, icon, running indicator and highlights. Safe to call
// again; whatever is already handled is skipped.
void ProcessButton(wux::FrameworkElement const& button) {
    Button& b = OnButtonAdded(button);
    ApplyButtonWidth(b, button);
    ApplyIconColumn(b);
    HandleStartButton(button);
    auto visit = [&](wux::FrameworkElement const& el) {
        auto name = el.Name();
        if (name == L"Icon") {
            TrackIconImage(el);
        } else if (name == L"RunningIndicator") {
            TrackIndicator(el, button);
            StyleIndicator(el, button);
        } else if (name == L"OverlayIcon") {
            TrackBadge(el);
        } else if ((name == L"BackgroundElement" || name == L"MultiWindowElement") &&
                   el.try_as<wuxc::Border>()) {
            HideHighlight(el);
        }
        return true;
    };
    ForEachDescendant(button, 6, visit);
}

// ---- Taskbars ----
// Each monitor's taskbar is a Taskbar.TaskbarFrame. The hooks report them, and
// the next frames walk their trees for buttons and the background (see
// ScanTaskbars), which also finds buttons that existed before the mod loaded.

std::vector<winrt::weak_ref<wux::FrameworkElement>> g_frames;

void NoteTaskbarFrame(wux::FrameworkElement const& frame) {
    if (!frame) return;
    for (auto& f : g_frames) {
        if (f.get() == frame) return;
    }
    g_frames.push_back(winrt::make_weak(frame));
    Wh_Log(L"Taskbar found");
    MarkPlatesDirty();
    ScheduleOverWindows(true);
}

// ---- System tray ----
// The tray row ("SystemTrayFrameGrid") is given the stock taskbar height and
// aligned to the bottom, so it isn't stretched to the taller taskbar.

constexpr double kStockTaskbarHeight = 48;

struct TrayRow {
    winrt::weak_ref<wux::FrameworkElement> element;
    wf::IInspectable originalHeight{nullptr};  // local values, may be UnsetValue
    wf::IInspectable originalAlignment{nullptr};
};

[[clang::no_destroy]] std::optional<std::list<TrayRow>> g_trayRows{std::in_place};

void FixTrayRow(wux::FrameworkElement const& row) {
    g_trayRows->remove_if([](TrayRow const& t) { return !t.element.get(); });
    bool known = false;
    for (auto& t : *g_trayRows) known |= t.element.get() == row;
    if (!known) {
        g_trayRows->push_back(
            {winrt::make_weak(row), row.ReadLocalValue(wux::FrameworkElement::HeightProperty()),
             row.ReadLocalValue(wux::FrameworkElement::VerticalAlignmentProperty())});
        Wh_Log(L"System tray found");
    }
    if (row.Height() != kStockTaskbarHeight) row.Height(kStockTaskbarHeight);
    if (row.VerticalAlignment() != wux::VerticalAlignment::Bottom) {
        row.VerticalAlignment(wux::VerticalAlignment::Bottom);
    }
}

void RestoreTrayRows() {
    for (auto& t : *g_trayRows) {
        auto el = t.element.get();
        if (!el) continue;
        try {
            RestoreLocalValue(el, wux::FrameworkElement::HeightProperty(), t.originalHeight);
            RestoreLocalValue(el, wux::FrameworkElement::VerticalAlignmentProperty(),
                              t.originalAlignment);
        } catch (...) {}
    }
    g_trayRows->clear();
}

// ---- Hide system tray ----
// With "Hide system tray" on, the tray frame is collapsed, and collapsed again
// if the taskbar changes its visibility.

struct HiddenTray {
    winrt::weak_ref<wux::FrameworkElement> element;
    wux::Visibility originalVisibility = wux::Visibility::Visible;
    int64_t visibilityToken = 0;
};

std::vector<HiddenTray> g_hiddenTrays;

void HideTray(wux::FrameworkElement const& tray) {
    if (!g_hideTray) return;
    g_hiddenTrays.erase(std::remove_if(g_hiddenTrays.begin(), g_hiddenTrays.end(),
                                       [](HiddenTray& t) { return !t.element.get(); }),
                        g_hiddenTrays.end());
    for (auto& t : g_hiddenTrays) {
        if (t.element.get() == tray) return;
    }
    auto& t = g_hiddenTrays.emplace_back();
    t.element = winrt::make_weak(tray);
    t.originalVisibility = tray.Visibility();
    t.visibilityToken = tray.RegisterPropertyChangedCallback(
        wux::UIElement::VisibilityProperty(),
        [](wux::DependencyObject const& sender, wux::DependencyProperty const&) {
            try {
                if (!g_hideTray) return;
                if (auto ui = sender.try_as<wux::UIElement>()) {
                    if (ui.Visibility() != wux::Visibility::Collapsed) {
                        ui.Visibility(wux::Visibility::Collapsed);
                    }
                }
            } catch (...) {}
        });
    tray.Visibility(wux::Visibility::Collapsed);
}

void RestoreHiddenTrays() {
    for (auto& t : g_hiddenTrays) {
        auto el = t.element.get();
        if (!el) continue;
        try {
            el.UnregisterPropertyChangedCallback(wux::UIElement::VisibilityProperty(),
                                                 t.visibilityToken);
            el.Visibility(t.originalVisibility);
        } catch (...) {}
    }
    g_hiddenTrays.clear();
}

// Finds the system tray next to `frame` (it's elsewhere in the same tree).
void ScanTray(wux::FrameworkElement const& frame) {
    auto root = frame.XamlRoot();
    auto content = root ? root.Content() : nullptr;
    if (!content) return;
    auto visit = [](wux::FrameworkElement const& el) {
        auto type = winrt::get_class_name(el);
        if (type == L"Taskbar.TaskbarFrame") return false;  // the dock; scanned elsewhere
        if (type == L"SystemTray.SystemTrayFrame") {
            HideTray(el);
            auto findRow = [](wux::FrameworkElement const& child) {
                if (child.Name() == L"SystemTrayFrameGrid") FixTrayRow(child);
                return false;
            };
            ForEachDescendant(el, 1, findRow);
            return false;
        }
        return true;
    };
    ForEachDescendant(content, 10, visit);
}

void ScanTaskbars() {
    // Forget whatever is gone.
    g_frames.erase(std::remove_if(g_frames.begin(), g_frames.end(),
                                  [](auto& f) { return !f.get(); }),
                   g_frames.end());
    g_buttons->remove_if([](Button const& b) { return !b.element.get(); });
    g_iconImages->remove_if([](IconImage const& i) { return !i.element.get(); });
    g_badges->remove_if([](OverlayBadge const& b) { return !b.element.get(); });
    g_indicators->remove_if([](Indicator const& i) { return !i.element.get(); });

    auto visit = [](wux::FrameworkElement const& el) {
        auto type = winrt::get_class_name(el);
        if (type == L"Taskbar.TaskListButton" || type == L"Taskbar.ExperienceToggleButton") {
            ProcessButton(el);
            return false;
        }
        if (type == L"Taskbar.TaskbarBackground") {
            HideBackground(el);
            return false;
        }
        return true;
    };
    for (auto& f : g_frames) {
        auto frame = f.get();
        if (!frame) continue;
        ForEachDescendant(frame, 12, visit);
        ScanTray(frame);
    }
}

// ---- Pointer (reported by the TaskbarFrame hooks) ----
// The pointer moved over a taskbar. It counts as over the dock when it's
// within the plate's width, gaps between icons included.
void OnTaskbarPointerMoved(wux::FrameworkElement const& frame,
                           wuxi::PointerRoutedEventArgs const& e) {
    NoteTaskbarFrame(frame);
    Plate* plate = nullptr;
    for (auto& p : *g_plates) {
        if (p.frame.get() == frame) {
            plate = &p;
            break;
        }
    }
    wux::UIElement row{nullptr};
    bool over = false;
    if (plate && plate->width > 0 && plate->root.Visibility() == wux::Visibility::Visible) {
        row = plate->row.get();
        auto panel = plate->panel.get();
        if (row && panel) {
            // Uses the dock's shown size, never less than its unmagnified one,
            // so an edge shrinking past a still pointer doesn't jitter. Above
            // the dock only counts while magnified.
            auto point = e.GetCurrentPoint(panel).Position();
            over = point.X >= std::min(plate->left, plate->baseLeft) &&
                   point.X <= std::max(plate->left + plate->width,
                                       plate->baseLeft + plate->baseWidth) &&
                   (point.Y >= plate->top || (g_pointerOver && g_rowParent.get() == row));
        }
    }
    if (!over) {
        if (g_pointerOver) {
            g_pointerOver = false;
            StartFrames();
        }
        return;
    }
    if (g_rowParent.get() != row) BuildRow(row);
    g_pointerX = e.GetCurrentPoint(row).Position().X;
    g_pointerOver = true;
    StartFrames();
}

void OnTaskbarPointerExited() {
    g_pointerOver = false;
    StartFrames();
}

void RemoveAppBars();
void ClipTaskbars();

void ResetAll() {
    StopFrames();
    try { RemovePlates(); } catch (...) {}
    try { StopTrash(); } catch (...) {}
    RestoreBackgrounds();
    RestoreHighlights();
    RestoreIconImages();
    RestoreBadges();
    RestoreStartButtons();
    for (auto& b : *g_buttons) {
        if (auto el = b.element.get()) {
            try {
                ReleaseButton(b);
                SetScale(el, 1.0f, 0);
                wuxh::ElementCompositionPreview::SetIsTranslationEnabled(el, false);
            } catch (...) {}
        }
    }
    RestoreStyledIndicators();
    RestoreIndicators();
    RestoreTrayRows();
    RestoreHiddenTrays();
    RemoveAppBars();
    ClipTaskbars();  // unclipped, as g_unloading is set
    if (HWND w = g_modWindow.exchange(nullptr)) DestroyWindow(w);
    g_row.clear();
    g_rowParent = nullptr;
    g_frames.clear();
    // Last, since everything above still reads them (see the no_destroy note
    // at g_buttons). Nothing touches them after this: the hooks check
    // g_unloading, and every callback and event handler is removed above.
    g_buttons.reset();
    g_iconImages.reset();
    g_badges.reset();
    g_plates.reset();
    g_indicators.reset();
    g_styledIndicators.reset();
    g_trayRows.reset();
}

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

using RunProc_t = void (*)(void*);

bool RunFromWindowThread(HWND hWnd, RunProc_t proc, void* param) {
    static const UINT msg = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
    struct Param { RunProc_t proc; void* param; };

    DWORD tid = GetWindowThreadProcessId(hWnd, nullptr);
    if (!tid) return false;
    if (tid == GetCurrentThreadId()) { proc(param); return true; }

    HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, [](int code, WPARAM w, LPARAM l) -> LRESULT {
        if (code == HC_ACTION) {
            auto* cwp = (const CWPSTRUCT*)l;
            if (cwp->message == msg) {
                auto* p = (Param*)cwp->lParam;
                p->proc(p->param);
            }
        }
        return CallNextHookEx(nullptr, code, w, l);
    }, nullptr, tid);
    if (!hook) return false;

    Param p{proc, param};
    SendMessage(hWnd, msg, 0, (LPARAM)&p);
    UnhookWindowsHookEx(hook);
    return true;
}

HWND FindTaskbar() {
    HWND result = nullptr;
    EnumWindows([](HWND hWnd, LPARAM l) -> BOOL {
        DWORD pid; WCHAR cls[32];
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassName(hWnd, cls, ARRAYSIZE(cls)) && _wcsicmp(cls, L"Shell_TrayWnd") == 0) {
            *(HWND*)l = hWnd;
            return FALSE;
        }
        return TRUE;
    }, (LPARAM)&result);
    return result;
}

// ---------------------------------------------------------------------------
// Reaching the taskbar's elements from its own code
// ---------------------------------------------------------------------------
// In a hook on a button or frame method, the XAML element is the interface at
// pThis + 3 pointers (as in "Taskbar Labels").

// Set while the mod unloads, so the hooks stop touching the taskbar.
std::atomic<bool> g_unloading = false;

wux::FrameworkElement ElementFromThis(void* pThis) {
    winrt::Windows::Foundation::IUnknown unknown;
    winrt::copy_from_abi(unknown, (void**)pThis + 3);
    return unknown.try_as<wux::FrameworkElement>();
}

// A taskbar app button (TaskListButton) updated itself: apply the dock's
// changes to it right away, before it's drawn, and note its taskbar so the
// rest is found on the next frames.
void OnTaskListButtonUpdated(void* pThis) {
    if (g_unloading) return;
    try {
        if (auto button = ElementFromThis(pThis)) {
            ProcessButton(button);
            NoteTaskbarFrame(FindTaskbarFrame(button));
        }
    } catch (...) {
        Wh_Log(L"Button update failed: 0x%08X", winrt::to_hresult());
    }
}

// ---- The pointer over the taskbar (as in "Taskbar Dock Animation") ----

using TaskbarFrame_OnPointer_t = int(WINAPI*)(void* pThis, void* pArgs);

// The TaskbarFrame these hooks were called for, or null for any other class.
wux::FrameworkElement TaskbarFrameFromThis(void* pThis) {
    wux::FrameworkElement element{nullptr};
    ((::IUnknown*)pThis)->QueryInterface(winrt::guid_of<wux::FrameworkElement>(),
                                         winrt::put_abi(element));
    if (!element || winrt::get_class_name(element) != L"Taskbar.TaskbarFrame") return nullptr;
    return element;
}

TaskbarFrame_OnPointer_t TaskbarFrame_OnPointerMoved_Original;
int WINAPI TaskbarFrame_OnPointerMoved_Hook(void* pThis, void* pArgs) {
    int result = TaskbarFrame_OnPointerMoved_Original(pThis, pArgs);
    if (g_unloading) return result;
    try {
        if (auto frame = TaskbarFrameFromThis(pThis)) {
            wuxi::PointerRoutedEventArgs args{nullptr};
            ((::IUnknown*)pArgs)->QueryInterface(
                winrt::guid_of<wuxi::PointerRoutedEventArgs>(), winrt::put_abi(args));
            if (args) OnTaskbarPointerMoved(frame, args);
        }
    } catch (...) {}
    return result;
}

TaskbarFrame_OnPointer_t TaskbarFrame_OnPointerExited_Original;
int WINAPI TaskbarFrame_OnPointerExited_Hook(void* pThis, void* pArgs) {
    int result = TaskbarFrame_OnPointerExited_Original(pThis, pArgs);
    if (g_unloading) return result;
    try {
        if (TaskbarFrameFromThis(pThis)) OnTaskbarPointerExited();
    } catch (...) {}
    return result;
}

// ---- Where a button's right-click menu opens (as in "Taskbar Multirow") ----
// The menu is centered on where the taskbar's layout put the button, which is
// wrong for File Explorer (moved by margins), so it's centered on the button's
// actual position. It's also lowered to the top of the dock (see
// PopupShiftDips).

bool g_placingJumpList = false;   // in CTaskListWnd::_ComputeJumpViewPosition
bool g_hasJumpListButton = false;  // a button's menu is being opened
wf::Rect g_jumpListButton{};       // its bounds, in its taskbar's XAML content

// Notes where the button whose menu is being opened is, and opens it.
template <typename F>
void OpenJumpListFor(wux::UIElement const& sender, F original) {
    g_hasJumpListButton = false;
    if (!g_unloading) {
        try {
            auto button = sender.try_as<wux::FrameworkElement>();
            auto root = button ? button.XamlRoot() : nullptr;
            auto content = root ? root.Content() : nullptr;
            if (content && FindButton(button)) {
                g_jumpListButton = button.TransformToVisual(content).TransformBounds(
                    {0, 0, (float)button.ActualWidth(), (float)button.ActualHeight()});
                g_hasJumpListButton = true;
            }
        } catch (...) {}
    }
    original();
    g_hasJumpListButton = false;
}

using TaskbarResources_OnTaskListButtonContextRequested_t =
    void(WINAPI*)(void* pThis, wux::UIElement const& sender, void* args);
TaskbarResources_OnTaskListButtonContextRequested_t
    TaskbarResources_OnTaskListButtonContextRequested_Original;
void WINAPI TaskbarResources_OnTaskListButtonContextRequested_Hook(
    void* pThis, wux::UIElement const& sender, void* args) {
    OpenJumpListFor(sender, [&] {
        TaskbarResources_OnTaskListButtonContextRequested_Original(pThis, sender, args);
    });
}

// The same, on builds that skip the one above.
using TaskListButtonHandlers_HandleContextRequested_t =
    void(WINAPI*)(wux::UIElement const& sender, void* args);
TaskListButtonHandlers_HandleContextRequested_t
    TaskListButtonHandlers_HandleContextRequested_Original;
void WINAPI TaskListButtonHandlers_HandleContextRequested_Hook(wux::UIElement const& sender,
                                                              void* args) {
    OpenJumpListFor(sender, [&] {
        TaskListButtonHandlers_HandleContextRequested_Original(sender, args);
    });
}

using CTaskListWnd_ComputeJumpViewPosition_t =
    HRESULT(WINAPI*)(void* pThis, void* taskBtnGroup, int param2, wf::Point* point,
                     wux::HorizontalAlignment* horizontal, wux::VerticalAlignment* vertical);
CTaskListWnd_ComputeJumpViewPosition_t CTaskListWnd_ComputeJumpViewPosition_Original;
HRESULT WINAPI CTaskListWnd_ComputeJumpViewPosition_Hook(void* pThis, void* taskBtnGroup,
                                                         int param2, wf::Point* point,
                                                         wux::HorizontalAlignment* horizontal,
                                                         wux::VerticalAlignment* vertical) {
    g_placingJumpList = true;
    HRESULT hr = CTaskListWnd_ComputeJumpViewPosition_Original(pThis, taskBtnGroup, param2,
                                                               point, horizontal, vertical);
    g_placingJumpList = false;
    return hr;
}

// Converts the button's bounds to screen pixels for placing the menu.
using ToRawPixelsInDesktopCoordinates_t = RECT(WINAPI*)(wf::Rect const& rect, UINT dpi,
                                                         HWND hWnd);
ToRawPixelsInDesktopCoordinates_t ToRawPixelsInDesktopCoordinates_Original;
RECT WINAPI ToRawPixelsInDesktopCoordinates_Hook(wf::Rect const& rect, UINT dpi, HWND hWnd) {
    if (g_placingJumpList && g_hasJumpListButton && !g_unloading) {
        wf::Rect moved = rect;
        moved.X = g_jumpListButton.X;
        moved.Width = g_jumpListButton.Width;
        // The menu opens above this rect's top, which is the taskbar window's
        // top: bring that down to the dock.
        float shift = 0;
        try { shift = PopupShiftDips(); } catch (...) {}
        if (shift > 0 && moved.Height > shift) {
            moved.Y += shift;
            moved.Height -= shift;
        }
        return ToRawPixelsInDesktopCoordinates_Original(moved, dpi, hWnd);
    }
    return ToRawPixelsInDesktopCoordinates_Original(rect, dpi, hWnd);
}

// ---- Dragging apps to a new spot (as in "Taskbar Multirow") ----
// File Explorer has a fixed spot, so dragging it is blocked. Other apps drag
// as usual, and the dock is laid out again after the drop.

winrt::weak_ref<wux::FrameworkElement> g_blockedDrag;  // File Explorer, while held

bool IsBlockedDrag(void* pThis) {
    try {
        auto blocked = g_blockedDrag.get();
        return blocked && ElementFromThis(pThis) == blocked;
    } catch (...) {
        return false;
    }
}

using TaskListButton_DragPoint_t = void(WINAPI*)(void* pThis, wf::Point point);
using TaskListButton_OnDragCompletedGesture_t = void(WINAPI*)(void* pThis);
TaskListButton_DragPoint_t TaskListButton_OnDragStartedGesture_Original;
void WINAPI TaskListButton_OnDragStartedGesture_Hook(void* pThis, wf::Point point) {
    if (!g_unloading) {
        try {
            auto button = ElementFromThis(pThis);
            if (button && IsFileExplorer(button)) {
                g_blockedDrag = winrt::make_weak(button);
                return;
            }
        } catch (...) {}
    }
    TaskListButton_OnDragStartedGesture_Original(pThis, point);
}

TaskListButton_DragPoint_t TaskListButton_UpdateDrag_Original;
void WINAPI TaskListButton_UpdateDrag_Hook(void* pThis, wf::Point point) {
    if (IsBlockedDrag(pThis)) return;
    TaskListButton_UpdateDrag_Original(pThis, point);
}

TaskListButton_OnDragCompletedGesture_t TaskListButton_OnDragCompletedGesture_Original;
void WINAPI TaskListButton_OnDragCompletedGesture_Hook(void* pThis) {
    if (IsBlockedDrag(pThis)) {
        g_blockedDrag = nullptr;
        return;
    }
    TaskListButton_OnDragCompletedGesture_Original(pThis);
    if (!g_unloading) MarkPlatesDirty();
}

// ---------------------------------------------------------------------------
// Taskbar height
// ---------------------------------------------------------------------------
// The taskbar window's height is set by Explorer's own code, so these hook the
// functions that report and apply it (as in m417z's "Taskbar height and icon
// size", height only). The hooks pass through when g_taskbarHeight is 0.

std::atomic<bool> g_applyingHeight = false;

// enumTaskbarSize: 0 = small, 1 = regular, 2 = large.
bool OverrideHeight(int enumTaskbarSize) {
    return g_taskbarHeight > 0 && (enumTaskbarSize == 1 || enumTaskbarSize == 2);
}

using VoidMethod_t = void(WINAPI*)(void* pThis);
using SetDouble_t = void(WINAPI*)(void* pThis, double value);

// ---- Height of the taskbar window ----

using TaskbarConfiguration_GetFrameSize_t = double(WINAPI*)(int enumTaskbarSize);
TaskbarConfiguration_GetFrameSize_t TaskbarConfiguration_GetFrameSize_Original;
double WINAPI TaskbarConfiguration_GetFrameSize_Hook(int enumTaskbarSize) {
    if (OverrideHeight(enumTaskbarSize)) return g_taskbarHeight;
    return TaskbarConfiguration_GetFrameSize_Original(enumTaskbarSize);
}

// ---- Height of the system tray (clock, notification area) ----

using SystemTray_GetFrameSize_t = double(WINAPI*)(void* pThis, int enumTaskbarSize);
SystemTray_GetFrameSize_t SystemTrayController_GetFrameSize_Original;
double WINAPI SystemTrayController_GetFrameSize_Hook(void* pThis, int enumTaskbarSize) {
    if (OverrideHeight(enumTaskbarSize)) return g_taskbarHeight;
    return SystemTrayController_GetFrameSize_Original(pThis, enumTaskbarSize);
}

// Same, for the taskbars on other monitors.
SystemTray_GetFrameSize_t SystemTraySecondaryController_GetFrameSize_Original;
double WINAPI SystemTraySecondaryController_GetFrameSize_Hook(void* pThis, int enumTaskbarSize) {
    if (OverrideHeight(enumTaskbarSize)) return g_taskbarHeight;
    return SystemTraySecondaryController_GetFrameSize_Original(pThis, enumTaskbarSize);
}

// While the tray resizes itself, make its frame exactly the taskbar's height.
thread_local bool g_inTrayUpdateFrameSize = false;

VoidMethod_t SystemTrayController_UpdateFrameSize_Original;
void WINAPI SystemTrayController_UpdateFrameSize_Hook(void* pThis) {
    g_inTrayUpdateFrameSize = true;
    SystemTrayController_UpdateFrameSize_Original(pThis);
    g_inTrayUpdateFrameSize = false;
}

VoidMethod_t SystemTraySecondaryController_UpdateFrameSize_Original;
void WINAPI SystemTraySecondaryController_UpdateFrameSize_Hook(void* pThis) {
    g_inTrayUpdateFrameSize = true;
    SystemTraySecondaryController_UpdateFrameSize_Original(pThis);
    g_inTrayUpdateFrameSize = false;
}

SetDouble_t SystemTrayFrame_Height_Original;
void WINAPI SystemTrayFrame_Height_Hook(void* pThis, double value) {
    if (g_inTrayUpdateFrameSize && g_taskbarHeight > 0) value = g_taskbarHeight;
    SystemTrayFrame_Height_Original(pThis, value);
}

// ---- The XAML frame inside the taskbar window ----

// Without lifting MaxHeight, the frame stays at the stock height.
SetDouble_t TaskbarFrame_MaxHeight_Original;

// Windows 11 22H2/23H2 set the frame's height through this.
SetDouble_t TaskbarFrame_Height_Original;
void WINAPI TaskbarFrame_Height_Hook(void* pThis, double value) {
    if (TaskbarFrame_MaxHeight_Original) {
        TaskbarFrame_MaxHeight_Original(pThis, std::numeric_limits<double>::infinity());
    }
    TaskbarFrame_Height_Original(pThis, value);
}

// Windows 11 24H2 and newer set it in TaskbarController::UpdateFrameHeight.
// The controller keeps its TaskbarFrame at an offset that's read from the
// start of OnGroupingModeChanged:  sub rsp, 28h / mov rax|r8, [rcx+offset]
void* TaskbarController_OnGroupingModeChanged_Address;

LONG GetTaskbarFrameOffset() {
    static LONG offset = []() -> LONG {
        const BYTE* p = (const BYTE*)TaskbarController_OnGroupingModeChanged_Address;
        if (p && p[0] == 0x48 && p[1] == 0x83 && p[2] == 0xEC &&
            (p[4] == 0x48 || p[4] == 0x4C) && p[5] == 0x8B && (p[6] & 0xC0) == 0x80) {
            LONG o = *(LONG*)(p + 7);
            if (o > 0 && o <= 0xFFFF) return o;
        }
        Wh_Log(L"Taskbar frame offset not found");
        return 0;
    }();
    return offset;
}

VoidMethod_t TaskbarController_UpdateFrameHeight_Original;
void WINAPI TaskbarController_UpdateFrameHeight_Hook(void* pThis) {
    wux::FrameworkElement frame{nullptr};
    try {
        LONG offset = GetTaskbarFrameOffset();
        void* taskbarFrame = offset ? *(void**)((BYTE*)pThis + offset) : nullptr;
        if (taskbarFrame) {
            ((::IUnknown**)taskbarFrame)[1]->QueryInterface(
                winrt::guid_of<wux::FrameworkElement>(), winrt::put_abi(frame));
        }
        if (frame) frame.MaxHeight(std::numeric_limits<double>::infinity());
    } catch (...) {}

    TaskbarController_UpdateFrameHeight_Original(pThis);

    if (!frame) return;
    // A taskbar, found as soon as its height is set (at startup too).
    if (!g_unloading) {
        try { NoteTaskbarFrame(frame); } catch (...) {}
    }

    // The grid holding the frame has a height of its own; keep it matching.
    try {
        auto grid = wuxm::VisualTreeHelper::GetParent(frame).try_as<wux::FrameworkElement>();
        if (grid) {
            double height = frame.Height();
            double gridHeight = grid.Height();
            if (gridHeight > 0 && gridHeight != height) grid.Height(height);
        }
    } catch (...) {}
}

// ---------------------------------------------------------------------------
// Icon resolution
// ---------------------------------------------------------------------------
// The taskbar loads icons at the size it thinks they're shown (24px times the
// display scaling). GetIconHeightInViewPixels now reports g_iconLoadSize, so
// icons load at full magnification; ApplyIconSize still shows them at the
// dock's icon size.
//
// Button layout code still gets the stock 24px, since it also uses the icon
// height to tell taskbar sizes apart. Start, Task View and other system
// buttons get the dock's icon size. Adapted from m417z's "Taskbar height and
// icon size".

// TaskbarFrame::GetMetrics picks the button width from the icon height.
thread_local bool g_inTaskbarFrameGetMetrics = false;

using GetIconHeightInViewPixels_t = double(WINAPI*)(void* pThis);
GetIconHeightInViewPixels_t TaskbarConfiguration_GetIconHeightInViewPixels_Original;
double WINAPI TaskbarConfiguration_GetIconHeightInViewPixels_Hook(void* pThis) {
    double height = TaskbarConfiguration_GetIconHeightInViewPixels_Original(pThis);
    // 16 = the "small taskbar buttons" setting, which this mod doesn't support.
    if (g_iconLoadSize <= 0 || g_inTaskbarFrameGetMetrics || height <= 16) return height;
    return g_iconLoadSize;
}

using TaskbarFrame_GetMetrics_t = void*(WINAPI*)(void* pThis, void* metrics);
TaskbarFrame_GetMetrics_t TaskbarFrame_GetMetrics_Original;
void* WINAPI TaskbarFrame_GetMetrics_Hook(void* pThis, void* metrics) {
    g_inTaskbarFrameGetMetrics = true;
    void* ret = TaskbarFrame_GetMetrics_Original(pThis, metrics);
    g_inTaskbarFrameGetMetrics = false;
    return ret;
}

// ---- App buttons: layout keeps seeing 24px ----

// Where a TaskListButton keeps its icon height, read from its setter, which
// starts by loading the current value:  movsd xmmN, qword ptr [rcx+offset]
void* TaskListButton_IconHeight_Address;

size_t GetIconHeightOffset() {
    static size_t offset = []() -> size_t {
        BYTE* p = (BYTE*)TaskListButton_IconHeight_Address;
        std::regex regex(R"(movsd xmm\d+, qword ptr \[rcx\+0x([0-9a-f]+)\])",
                         std::regex_constants::icase);
        for (int i = 0; p && i < 30; i++) {
            WH_DISASM_RESULT result;
            if (!Wh_Disasm(p, &result)) break;
            p += result.length;
            std::string_view text = result.text;
            if (text == "ret") break;
            std::match_results<std::string_view::const_iterator> match;
            if (std::regex_match(text.begin(), text.end(), match, regex)) {
                size_t o = 0;
                std::from_chars(&*match[1].first, &*match[1].first + match[1].length(), o, 16);
                Wh_Log(L"Icon height offset: 0x%zX", o);
                return o <= 0xFFFF ? o : 0;
            }
        }
        Wh_Log(L"Icon height offset not found; icon resolution unchanged");
        return 0;
    }();
    return offset;
}

// Runs `original` with the button's icon height set to the stock 24px, then
// puts the real value back.
template <typename F>
void WithStockIconHeight(void* pThis, F original) {
    size_t offset = g_iconLoadSize > 0 ? GetIconHeightOffset() : 0;
    if (!offset) return original();
    double* iconHeight = (double*)((BYTE*)pThis + offset);
    double saved = *iconHeight;
    *iconHeight = kStockIconSize;
    original();
    *iconHeight = saved;
}

#define STOCK_ICON_HEIGHT_HOOK(name)                                              \
    VoidMethod_t TaskListButton_##name##_Original;                                \
    void WINAPI TaskListButton_##name##_Hook(void* pThis) {                       \
        WithStockIconHeight(pThis, [=] { TaskListButton_##name##_Original(pThis); }); \
    }

STOCK_ICON_HEIGHT_HOOK(UpdateMultiWindowClip)
STOCK_ICON_HEIGHT_HOOK(CreateMultiWindowClip)
STOCK_ICON_HEIGHT_HOOK(UpdateBadge)

// These two also run whenever a button is set up or changes state (hover,
// active window, a second window...), which is when the dock applies its
// changes to it (see OnTaskListButtonUpdated).
VoidMethod_t TaskListButton_UpdateButtonPadding_Original;
void WINAPI TaskListButton_UpdateButtonPadding_Hook(void* pThis) {
    WithStockIconHeight(pThis, [=] { TaskListButton_UpdateButtonPadding_Original(pThis); });
    OnTaskListButtonUpdated(pThis);
}

VoidMethod_t TaskListButton_UpdateVisualStates_Original;
void WINAPI TaskListButton_UpdateVisualStates_Hook(void* pThis) {
    WithStockIconHeight(pThis, [=] { TaskListButton_UpdateVisualStates_Original(pThis); });
    OnTaskListButtonUpdated(pThis);
}

// Sets the width of the button's icon column back to the stock one; widen it
// again right after (see ApplyIconColumn).
VoidMethod_t TaskListButton_UpdateIconColumnDefinition_Original;
void WINAPI TaskListButton_UpdateIconColumnDefinition_Hook(void* pThis) {
    TaskListButton_UpdateIconColumnDefinition_Original(pThis);
    OnTaskListButtonUpdated(pThis);
}

using TaskListButton_OverlayIcon_t = void(WINAPI*)(void* pThis, void* stream);
TaskListButton_OverlayIcon_t TaskListButton_OverlayIcon_Original;
void WINAPI TaskListButton_OverlayIcon_Hook(void* pThis, void* stream) {
    WithStockIconHeight(pThis, [=] { TaskListButton_OverlayIcon_Original(pThis, stream); });
}

// ---- Start, Task View and other system buttons ----

// Their icon is shown at the dock's icon size, not the loading size.
SetDouble_t ExperienceToggleButton_IconHeight_Original;
void WINAPI ExperienceToggleButton_IconHeight_Hook(void* pThis, double height) {
    if (g_iconLoadSize > 0 && height > 16) height = g_iconSize;
    ExperienceToggleButton_IconHeight_Original(pThis, height);
}

// Their padding is worked out for the stock 24px, as before. Setting the
// height calls UpdateButtonPadding again, which the flag skips.
using GetDouble_t = double(WINAPI*)(void* pThis);
GetDouble_t ExperienceToggleButton_IconHeight_get;
thread_local bool g_settingToggleIconHeight = false;

void SetToggleIconHeight(void* pThis, double height) {
    g_settingToggleIconHeight = true;
    ExperienceToggleButton_IconHeight_Original(pThis, height);
    g_settingToggleIconHeight = false;
}

VoidMethod_t ExperienceToggleButton_UpdateButtonPadding_Original;
void WINAPI ExperienceToggleButton_UpdateButtonPadding_Hook(void* pThis) {
    if (g_settingToggleIconHeight) return;
    double height = kStockIconSize;
    if (g_iconLoadSize > 0 && ExperienceToggleButton_IconHeight_get &&
        ExperienceToggleButton_IconHeight_Original) {
        height = ExperienceToggleButton_IconHeight_get(pThis);
    }
    bool swap = height > 16 && height != kStockIconSize;
    if (swap) SetToggleIconHeight(pThis, kStockIconSize);
    ExperienceToggleButton_UpdateButtonPadding_Original(pThis);
    if (swap) SetToggleIconHeight(pThis, height);
}

// Taskbar extensions such as widgets: shown at the dock's icon size too.
SetDouble_t TaskbarComponentHost_IconHeight_Original;
void WINAPI TaskbarComponentHost_IconHeight_Hook(void* pThis, double height) {
    if (g_iconLoadSize > 0 && height > 16) height = g_iconSize;
    TaskbarComponentHost_IconHeight_Original(pThis, height);
}

// ---- Making Explorer apply a new height ----

// Explorer re-reads the height when it handles a settings change; this makes
// it also resize the taskbar window right away.
VoidMethod_t TrayUI__StuckTrayChange_Original;

using TrayUI__HandleSettingChange_t = void(WINAPI*)(void*, void*, void*, void*, void*);
TrayUI__HandleSettingChange_t TrayUI__HandleSettingChange_Original;
void WINAPI TrayUI__HandleSettingChange_Hook(void* pThis, void* p1, void* p2, void* p3, void* p4) {
    TrayUI__HandleSettingChange_Original(pThis, p1, p2, p3, p4);
    if (g_applyingHeight) {
        TrayUI__StuckTrayChange_Original(pThis);
    } else if (!g_unloading) {
        ScheduleOverWindows(true);  // re-read the user's autohide setting
    }
}

void ApplyTaskbarHeight() {
    HWND tb = FindTaskbar();
    if (!tb) return;
    g_applyingHeight = true;
    SendMessage(tb, WM_SETTINGCHANGE, SPI_SETLOGICALDPIOVERRIDE, 0);
    g_applyingHeight = false;

    // Make the taskbar reload its icons, at the new resolution.
    if (HWND rebar = FindWindowEx(tb, nullptr, L"ReBarWindow32", nullptr)) {
        if (HWND taskSw = FindWindowEx(rebar, nullptr, L"MSTaskSwWClass", nullptr)) {
            SendMessage(taskSw, 0x452, 3, 0);
        }
    }
}

// ---- Keeping the dock over windows ----
// Maximized windows reach down to the top of the dock, and magnified icons
// rise over them. Three things make that work:
// - Windows' "Automatically hide the taskbar" is turned on while the mod is
//   loaded, so Windows keeps no space free for the taskbar. The taskbar is
//   kept from actually hiding unless "Auto-hide the dock" is on.
// - An app bar keeps a strip the height of the dock free on each screen.
// - The taskbar window, taller than the dock, is clipped to that strip while
//   no icon is magnified.
// With "Auto-hide the dock" on, the app bar and clip are removed, and the
// taskbar hides by itself.

// TrayUI::_HandleTrayPrivateSettingMessage: gets or sets auto-hide.
constexpr UINT kTraySettingMessage = WM_USER + 0x1CA;
constexpr WPARAM kTraySettingAutoHideGet = 3;
constexpr WPARAM kTraySettingAutoHideSet = 4;
constexpr UINT_PTR kTrayHideTimer = 2;

// Whether the mod forced Windows' auto-hide on, and its value before. Saved so
// it can be restored after Explorer restarts.
bool g_managingAutoHide = false;
bool g_autoHideBefore = false;

// Saved per user, since the mod's storage can be shared between users.
std::wstring UserValueName(PCWSTR name) {
    static std::wstring sid = [] {
        std::wstring result;
        HANDLE token;
        if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) return result;
        alignas(TOKEN_USER) BYTE buffer[sizeof(TOKEN_USER) + SECURITY_MAX_SID_SIZE];
        DWORD size;
        PWSTR text;
        if (GetTokenInformation(token, TokenUser, buffer, sizeof(buffer), &size) &&
            ConvertSidToStringSidW(((TOKEN_USER*)buffer)->User.Sid, &text)) {
            result = text;
            LocalFree(text);
        }
        CloseHandle(token);
        return result;
    }();
    return std::wstring(name) + L"_" + sid;
}

// True when the dock stays put with a strip kept free under it (not auto-hide).
bool KeepTaskbarShown() { return !g_autoHideDock && !g_unloading; }

// Windows' auto-hide stays on while the mod is loaded.
bool WantAutoHideOn() { return !g_unloading; }

void ApplyAutoHide() {
    HWND tb = FindTaskbar();
    if (!tb) return;

    bool actual = SendMessage(tb, kTraySettingMessage, kTraySettingAutoHideGet, 0) != 0;

    // Saved state is stale (we forced it on, but it's off): drop it.
    if (g_managingAutoHide && !actual && !g_unloading) {
        g_managingAutoHide = false;
    }
    // Not forced: Windows' value is the user's own.
    if (!g_managingAutoHide) {
        g_autoHideBefore = actual;
    }

    if (WantAutoHideOn()) {
        if (!g_managingAutoHide) {
            g_managingAutoHide = true;
            // Save the original value first, in case Explorer crashes.
            Wh_SetIntValue(UserValueName(L"autoHideBefore").c_str(), g_autoHideBefore);
            Wh_SetIntValue(UserValueName(L"managingAutoHide").c_str(), 1);
        }
        SendMessage(tb, kTraySettingMessage, kTraySettingAutoHideSet, TRUE);
        // Start Windows' hide timer; it only hides if the pointer is away.
        if (g_autoHideDock) SetTimer(tb, kTrayHideTimer, 100, nullptr);
    } else if (g_managingAutoHide) {
        SendMessage(tb, kTraySettingMessage, kTraySettingAutoHideSet, g_autoHideBefore);
        g_managingAutoHide = false;
    }

    Wh_Log(L"[auto-hide] dock auto-hide: %d, keep shown: %d, forced on: %d",
       g_autoHideDock, KeepTaskbarShown(), g_managingAutoHide);
    Wh_SetIntValue(UserValueName(L"managingAutoHide").c_str(), g_managingAutoHide);
    Wh_SetIntValue(UserValueName(L"autoHideBefore").c_str(), g_autoHideBefore);
}

using TrayUI__Hide_t = void(WINAPI*)(void* pThis);
TrayUI__Hide_t TrayUI__Hide_Original;
void WINAPI TrayUI__Hide_Hook(void* pThis) {
    if (KeepTaskbarShown()) {
        if (HWND tb = FindTaskbar()) KillTimer(tb, kTrayHideTimer);
        return;
    }
    TrayUI__Hide_Original(pThis);
}

// The same, for the taskbars on other screens.
using CSecondaryTray__AutoHide_t = void(WINAPI*)(void* pThis, bool param1);
CSecondaryTray__AutoHide_t CSecondaryTray__AutoHide_Original;
void WINAPI CSecondaryTray__AutoHide_Hook(void* pThis, bool param1) {
    if (KeepTaskbarShown()) return;
    CSecondaryTray__AutoHide_Original(pThis, param1);
}

// Calls `f` with each taskbar window (one per screen).
template <typename F>
void ForEachTaskbarWindow(F f) {
    EnumWindows(
        [](HWND w, LPARAM l) -> BOOL {
            DWORD pid;
            WCHAR cls[32];
            if (GetWindowThreadProcessId(w, &pid) && pid == GetCurrentProcessId() &&
                GetClassName(w, cls, ARRAYSIZE(cls)) &&
                (!_wcsicmp(cls, L"Shell_TrayWnd") || !_wcsicmp(cls, L"Shell_SecondaryTrayWnd"))) {
                (*(F*)l)(w);
            }
            return TRUE;
        },
        (LPARAM)&f);
}

// ===========================================================================
// Popups above the dock
// ===========================================================================
// Hover previews (A) and hover name tooltips (B) are placed above the top of
// the tall taskbar window. They're moved down to just above the dock, or the
// biggest magnified icon (see "Where popups above the dock go"). Both can be
// windows, so their window position hooks are shared (C).

// ---------------------------------------------------------------------------
// A. Hover previews (thumbnails)
// ---------------------------------------------------------------------------

// A1. The XAML flyout (current Windows 11 builds).
// The preview is a XAML FlyoutFrame in the full-screen island window, so
// moving windows doesn't work. FlyoutFrame::UpdateFlyoutPosition converts its
// position with MapWindowPoints, so a downward offset is added to that point
// while it runs (as in "Taskbar on top").
//
// How far (DIPs) the stock preview's bottom edge sits above the taskbar
// window's top. Raise to move previews down, lower to move them up.
constexpr float kFlyoutStockGap = 12;

thread_local bool g_inUpdateFlyoutPosition = false;

VoidMethod_t FlyoutFrame_UpdateFlyoutPosition_Original;
void WINAPI FlyoutFrame_UpdateFlyoutPosition_Hook(void* pThis) {
    bool previous = g_inUpdateFlyoutPosition;
    g_inUpdateFlyoutPosition = true;
    FlyoutFrame_UpdateFlyoutPosition_Original(pThis);
    g_inUpdateFlyoutPosition = previous;
}

using MapWindowPoints_t = decltype(&MapWindowPoints);
MapWindowPoints_t MapWindowPoints_Original;
int WINAPI MapWindowPoints_Hook(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoints, UINT cPoints) {
    int ret = MapWindowPoints_Original(hWndFrom, hWndTo, lpPoints, cPoints);
    if (!g_inUpdateFlyoutPosition || g_unloading || !lpPoints || cPoints == 0) return ret;

    try {
        HWND tb = FindTaskbar();
        UINT dpi = tb ? GetDpiForWindow(tb) : 96;
        float shiftDips = PopupShiftDips() + kFlyoutStockGap;
        int shift = MulDiv((int)std::ceil(shiftDips), dpi, 96);
        for (UINT i = 0; i < cPoints; i++) lpPoints[i].y += shift;
    } catch (...) {}
    return ret;
}

// A2. Previews that are windows of their own (builds where the preview isn't
// a XAML flyout). Moved by the window position hooks in section C.
bool IsHoverPreviewWindow(std::wstring const& lowerClass) {
    return lowerClass.find(L"thumbnail") != std::wstring::npos ||
           lowerClass.find(L"tasklist") != std::wstring::npos;
}

// ---------------------------------------------------------------------------
// B. Hover name tooltips
// ---------------------------------------------------------------------------
// The name above an icon is a XAML ToolTip shown in a
// "Xaml_WindowedPopupClass" window. PlaceTooltip centers it on the icon; the
// window position hooks (C) move it down, which is what this class check is
// for. Only windows whose bottom edge is just above the taskbar window's top
// are moved (see WindowPopupShiftPx).
bool IsNameTooltipWindow(std::wstring const& lowerClass) {
    return lowerClass.find(L"tooltip") != std::wstring::npos ||
           lowerClass.find(L"windowedpopup") != std::wstring::npos;
}

// ---------------------------------------------------------------------------
// C. Window position hooks (hover previews A2, and name tooltips B)
// ---------------------------------------------------------------------------
// Both are placed with SetWindowPos or DeferWindowPos. Other window classes
// are left alone.
using SetWindowPos_t = decltype(&SetWindowPos);
SetWindowPos_t SetWindowPos_Original;

// The last popup window moved, and where it was put, so that the same
// position being set again isn't shifted a second time.
std::atomic<HWND> g_lastShiftedWnd = nullptr;
std::atomic<int> g_lastShiftedY = INT_MIN;

// How far down (in pixels) a popup being placed at this rect should move: 0
// unless it's a hover preview or name tooltip whose bottom edge is near the
// top of a taskbar on the same monitor.
int WindowPopupShiftPx(HWND hWnd, int x, int y, int cx, int cy) {
    WCHAR cls[64];
    if (!GetClassName(hWnd, cls, ARRAYSIZE(cls))) return 0;
    std::wstring lowerClass(cls);
    std::transform(lowerClass.begin(), lowerClass.end(), lowerClass.begin(), ::towlower);
    if (!IsHoverPreviewWindow(lowerClass) && !IsNameTooltipWindow(lowerClass)) return 0;
    if (hWnd == g_lastShiftedWnd.load() && y == g_lastShiftedY.load()) return 0;

    RECT r{x, y, x + cx, y + cy};
    HMONITOR monitor = MonitorFromRect(&r, MONITOR_DEFAULTTONEAREST);
    int shift = 0;
    ForEachTaskbarWindow([&](HWND tb) {
        if (GetWindowThreadProcessId(tb, nullptr) != GetCurrentThreadId()) return;
        if (MonitorFromWindow(tb, MONITOR_DEFAULTTONEAREST) != monitor) return;
        RECT w;
        if (!GetWindowRect(tb, &w)) return;
        UINT dpi = GetDpiForWindow(tb);
        int bottom = y + cy;
        // Placed just above the taskbar window's top, give or take its margin.
        if (bottom < w.top - MulDiv(80, dpi, 96) || bottom > w.top + MulDiv(12, dpi, 96)) {
            return;
        }
        float magTop = g_dockBottomGap + (g_dockHeight - g_iconSize) / 2 + g_scale * g_iconSize;
        float insetDips = std::max(DockTopInset(), g_pointerOver ? magTop : 0.0f) + kPreviewGap;
        int target = (int)w.bottom - MulDiv((int)std::ceil(insetDips), dpi, 96);
        shift = std::max(0, target - bottom);
    });
    return shift;
}

BOOL WINAPI SetWindowPos_Hook(HWND hWnd, HWND after, int X, int Y, int cx, int cy, UINT flags) {
    if (!g_unloading && !(flags & SWP_NOMOVE)) {
        int shift = 0;
        try { shift = WindowPopupShiftPx(hWnd, X, Y, cx, cy); } catch (...) {}
        if (shift > 0) {
            g_lastShiftedWnd.store(hWnd);
            Y += shift;
            g_lastShiftedY.store(Y);
        }
    }
    return SetWindowPos_Original(hWnd, after, X, Y, cx, cy, flags);
}

using DeferWindowPos_t = decltype(&DeferWindowPos);
DeferWindowPos_t DeferWindowPos_Original;
HDWP WINAPI DeferWindowPos_Hook(HDWP hdwp, HWND hWnd, HWND after, int X, int Y, int cx, int cy,
                                UINT flags) {
    if (!g_unloading && !(flags & SWP_NOMOVE)) {
        int shift = 0;
        try { shift = WindowPopupShiftPx(hWnd, X, Y, cx, cy); } catch (...) {}
        if (shift > 0) {
            g_lastShiftedWnd.store(hWnd);
            Y += shift;
            g_lastShiftedY.store(Y);
        }
    }
    return DeferWindowPos_Original(hdwp, hWnd, after, X, Y, cx, cy, flags);
}

// The strip kept free at the bottom of the screen, in pixels: the dock and
// the gap under it, or the system tray if that's taller.
int StripHeight(UINT dpi) {
    float height = std::max(g_dockBottomGap + g_dockHeight, (float)kStockTaskbarHeight);
    return MulDiv((int)std::ceil(height), dpi, 96);
}

void ClipTaskbars() {
    ForEachTaskbarWindow([](HWND tb) {
        RECT window, have;
        if (!GetWindowRect(tb, &window)) return;
        int type = GetWindowRgnBox(tb, &have);
        if (!KeepTaskbarShown() || g_dockExpanded) {
            if (type != ERROR) SetWindowRgn(tb, nullptr, TRUE);
            return;
        }
        RECT want{0, 0, window.right - window.left, window.bottom - window.top};
        want.top = std::max(0, (int)want.bottom - StripHeight(GetDpiForWindow(tb)));
        if (type == SIMPLEREGION && EqualRect(&have, &want)) return;
        SetWindowRgn(tb, CreateRectRgnIndirect(&want), TRUE);
    });
}

struct AppBar {
    HWND hwnd;
    RECT rect;  // the strip it keeps free
};
std::vector<AppBar> g_appBars;  // one per screen with a taskbar

void RemoveAppBars() {
    for (auto& bar : g_appBars) {
        APPBARDATA abd{sizeof(abd)};
        abd.hWnd = bar.hwnd;
        SHAppBarMessage(ABM_REMOVE, &abd);
        DestroyWindow(bar.hwnd);
    }
    g_appBars.clear();
}

// Keeps `rect` free, at the bottom of a screen.
void AddAppBar(RECT const& rect) {
    HWND w = CreateWindowEx(WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, kWindowClass, L"", WS_POPUP, 0, 0,
                            0, 0, nullptr, nullptr, ModuleInstance(), nullptr);
    if (!w) return;
    g_appBars.push_back({w, rect});

    APPBARDATA abd{sizeof(abd)};
    abd.hWnd = w;
    abd.uCallbackMessage = kAppBarMessage;
    SHAppBarMessage(ABM_NEW, &abd);
    abd.uEdge = ABE_BOTTOM;
    abd.rc = rect;
    SHAppBarMessage(ABM_QUERYPOS, &abd);
    abd.rc.top = abd.rc.bottom - (rect.bottom - rect.top);
    SHAppBarMessage(ABM_SETPOS, &abd);
    Wh_Log(L"[magnify over windows] keeping %d px free at the bottom of a screen",
           (int)(rect.bottom - rect.top));
}

// Makes the app bars match the screens with a taskbar. Only changes them
// when they don't match: changing them is announced to every app bar, these
// included, which would otherwise make them again, and again.
void UpdateAppBars() {
    std::vector<RECT> want;
    if (KeepTaskbarShown()) {
        ForEachTaskbarWindow([&want](HWND tb) {
            HMONITOR monitor = MonitorFromWindow(tb, MONITOR_DEFAULTTONEAREST);
            MONITORINFO info{sizeof(info)};
            UINT dpiX, dpiY;
            if (!GetMonitorInfo(monitor, &info) ||
                FAILED(GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI, &dpiX, &dpiY))) {
                return;
            }
            RECT rect = info.rcMonitor;
            rect.top = rect.bottom - StripHeight(dpiY);
            want.push_back(rect);
        });
    }
    bool same = want.size() == g_appBars.size();
    for (size_t i = 0; same && i < want.size(); i++) {
        same = EqualRect(&want[i], &g_appBars[i].rect);
    }
    if (same) return;
    RemoveAppBars();
    if (want.empty() || !RegisterWindowClass()) return;
    for (auto& rect : want) AddAppBar(rect);
}

// Updates the app bars and the clipping, and auto-hide too if `autoHide`, on
// the taskbar's thread, from its message loop: outside the taskbar's own
// code, and once for any number of requests until then.
int g_overWindowsPending = 0;  // 1 = update, 2 = and auto-hide

void ScheduleOverWindows(bool autoHide) {
    bool post = g_overWindowsPending == 0;
    g_overWindowsPending = std::max(g_overWindowsPending, autoHide ? 2 : 1);
    if (!post) return;
    HWND w = EnsureModWindow();
    if (!w || !PostMessage(w, kUpdateOverWindowsMessage, 0, 0)) g_overWindowsPending = 0;
}

void UpdateOverWindows() {
    int pending = std::exchange(g_overWindowsPending, 0);
    if (g_unloading || !pending) return;
    if (pending == 2) ApplyAutoHide();
    UpdateAppBars();
    ClipTaskbars();
}

// Applies "Magnify over windows" and "Auto-hide the dock" as they're now
// set. Also done whenever a taskbar appears (see NoteTaskbarFrame), since the
// mod is often loaded before there is one.
void ApplyMagnifyOverWindows() {
    if (HWND tb = FindTaskbar()) {
        RunFromWindowThread(tb, [](void*) { ScheduleOverWindows(true); }, nullptr);
    }
}

LRESULT CALLBACK ModWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case kAppBarMessage:
            if (wParam == ABN_POSCHANGED) ScheduleOverWindows(false);
            return 0;
        case WM_DISPLAYCHANGE:
            ScheduleOverWindows(false);
            break;
        case kUpdateOverWindowsMessage:
            UpdateOverWindows();
            return 0;
        case kTrashChangedMessage:
            CheckRecycleBinSoon();
            return 0;
        case kTrashCheckedMessage:
            if (!g_unloading) {
                try { UpdateTrashIcons(); } catch (...) {}
            }
            return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

// ---- Installing the hooks ----

bool HookTaskbarDllSymbols() {
    HMODULE module = LoadLibraryEx(L"taskbar.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!module) return false;

    WindhawkUtils::SYMBOL_HOOK taskbarDllHooks[] = {
        {
            {LR"(public: void __cdecl TrayUI::_StuckTrayChange(void))"},
            &TrayUI__StuckTrayChange_Original,
        },
        {
            {LR"(public: void __cdecl TrayUI::_HandleSettingChange(struct HWND__ *,unsigned int,unsigned __int64,__int64))"},
            &TrayUI__HandleSettingChange_Original,
            TrayUI__HandleSettingChange_Hook,
        },
        // Magnify over windows: the taskbar doesn't auto-hide
        {
            {LR"(public: void __cdecl TrayUI::_Hide(void))"},
            &TrayUI__Hide_Original,
            TrayUI__Hide_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl CSecondaryTray::_AutoHide(bool))"},
            &CSecondaryTray__AutoHide_Original,
            CSecondaryTray__AutoHide_Hook,
            true,
        },
        // Where a button's right-click menu opens
        {
            {LR"(protected: long __cdecl CTaskListWnd::_ComputeJumpViewPosition(struct ITaskBtnGroup *,int,struct Windows::Foundation::Point &,enum Windows::UI::Xaml::HorizontalAlignment &,enum Windows::UI::Xaml::VerticalAlignment &)const )"},
            &CTaskListWnd_ComputeJumpViewPosition_Original,
            CTaskListWnd_ComputeJumpViewPosition_Hook,
            true,
        },
        {
            {LR"(struct tagRECT __cdecl ToRawPixelsInDesktopCoordinates(struct winrt::Windows::Foundation::Rect const &,unsigned int,struct HWND__ *))"},
            &ToRawPixelsInDesktopCoordinates_Original,
            ToRawPixelsInDesktopCoordinates_Hook,
            true,
        },
    };
    return WindhawkUtils::HookSymbols(module, taskbarDllHooks, ARRAYSIZE(taskbarDllHooks));
}

// The name the symbol extraction script expects for a list of hooks that
// isn't one of the hook arrays itself.
using COMBINED_SH = WindhawkUtils::SYMBOL_HOOK;

// The system tray's hooks. Newer builds keep the tray in SystemTray.dll,
// older ones in Taskbar.View.dll (see TaskbarViewHasTray).
std::vector<COMBINED_SH> GetTrayHooks() {
    // SystemTray.dll, Taskbar.View.dll
    WindhawkUtils::SYMBOL_HOOK trayHooks[] = {
        {
            {LR"(private: double __cdecl winrt::SystemTray::implementation::SystemTrayController::GetFrameSize(enum winrt::WindowsUdk::UI::Shell::TaskbarSize))"},
            &SystemTrayController_GetFrameSize_Original,
            SystemTrayController_GetFrameSize_Hook,
            true,
        },
        {
            {LR"(private: double __cdecl winrt::SystemTray::implementation::SystemTraySecondaryController::GetFrameSize(enum winrt::WindowsUdk::UI::Shell::TaskbarSize))"},
            &SystemTraySecondaryController_GetFrameSize_Original,
            SystemTraySecondaryController_GetFrameSize_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::SystemTray::implementation::SystemTrayController::UpdateFrameSize(void))"},
            &SystemTrayController_UpdateFrameSize_Original,
            SystemTrayController_UpdateFrameSize_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::SystemTray::implementation::SystemTraySecondaryController::UpdateFrameSize(void))"},
            &SystemTraySecondaryController_UpdateFrameSize_Original,
            SystemTraySecondaryController_UpdateFrameSize_Hook,
            true,
        },
        {
            {LR"(public: __cdecl winrt::impl::consume_Windows_UI_Xaml_IFrameworkElement<struct winrt::SystemTray::SystemTrayFrame>::Height(double)const )"},
            &SystemTrayFrame_Height_Original,
            SystemTrayFrame_Height_Hook,
            true,
        },
    };
    return {std::make_move_iterator(std::begin(trayHooks)),
            std::make_move_iterator(std::end(trayHooks))};
}

bool HookTaskbarViewSymbols(HMODULE module, bool withTray) {
    // Taskbar.View.dll
    WindhawkUtils::SYMBOL_HOOK taskbarViewHooks[] = {
        {
            {LR"(public: static double __cdecl winrt::Taskbar::implementation::TaskbarConfiguration::GetFrameSize(enum winrt::WindowsUdk::UI::Shell::TaskbarSize))"},
            &TaskbarConfiguration_GetFrameSize_Original,
            TaskbarConfiguration_GetFrameSize_Hook,
            true,
        },
        {
            {LR"(public: __cdecl winrt::impl::consume_Windows_UI_Xaml_IFrameworkElement<struct winrt::Taskbar::implementation::TaskbarFrame>::MaxHeight(double)const )"},
            &TaskbarFrame_MaxHeight_Original,
            nullptr,
            true,
        },
        {
            {LR"(public: __cdecl winrt::impl::consume_Windows_UI_Xaml_IFrameworkElement<struct winrt::Taskbar::implementation::TaskbarFrame>::Height(double)const )"},
            &TaskbarFrame_Height_Original,
            TaskbarFrame_Height_Hook,
            true,  // Gone in 24H2.
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskbarController::OnGroupingModeChanged(void))"},
            &TaskbarController_OnGroupingModeChanged_Address,
            nullptr,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskbarController::UpdateFrameHeight(void))"},
            &TaskbarController_UpdateFrameHeight_Original,
            TaskbarController_UpdateFrameHeight_Hook,
            true,
        },
        {
            {LR"(public: virtual int __cdecl winrt::impl::produce<struct winrt::Taskbar::implementation::TaskbarFrame,struct winrt::Windows::UI::Xaml::Controls::IControlOverrides>::OnPointerMoved(void *))"},
            &TaskbarFrame_OnPointerMoved_Original,
            TaskbarFrame_OnPointerMoved_Hook,
            true,
        },
        {
            {LR"(public: virtual int __cdecl winrt::impl::produce<struct winrt::Taskbar::implementation::TaskbarFrame,struct winrt::Windows::UI::Xaml::Controls::IControlOverrides>::OnPointerExited(void *))"},
            &TaskbarFrame_OnPointerExited_Original,
            TaskbarFrame_OnPointerExited_Hook,
            true,
        },

        // Hover previews (thumbnails): where the XAML flyout is placed
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::FlyoutFrame::UpdateFlyoutPosition(void))"},
            &FlyoutFrame_UpdateFlyoutPosition_Original,
            FlyoutFrame_UpdateFlyoutPosition_Hook,
            true,
        },

        // Where a button's right-click menu opens
        {
            {LR"(public: void __cdecl winrt::Taskbar::implementation::TaskbarResources::OnTaskListButtonContextRequested(struct winrt::Windows::UI::Xaml::UIElement const &,struct winrt::Windows::UI::Xaml::Input::ContextRequestedEventArgs const &))"},
            &TaskbarResources_OnTaskListButtonContextRequested_Original,
            TaskbarResources_OnTaskListButtonContextRequested_Hook,
            true,
        },
        {
            {LR"(public: static void __cdecl winrt::Taskbar::implementation::TaskListButtonHandlers::HandleContextRequested(struct winrt::Windows::UI::Xaml::UIElement const &,struct winrt::Windows::UI::Xaml::Input::ContextRequestedEventArgs const &))"},
            &TaskListButtonHandlers_HandleContextRequested_Original,
            TaskListButtonHandlers_HandleContextRequested_Hook,
            true,
        },

        // Dragging apps to a new spot
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::OnDragStartedGesture(struct winrt::Windows::Foundation::Point))"},
            &TaskListButton_OnDragStartedGesture_Original,
            TaskListButton_OnDragStartedGesture_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateDrag(struct winrt::Windows::Foundation::Point))"},
            &TaskListButton_UpdateDrag_Original,
            TaskListButton_UpdateDrag_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::OnDragCompletedGesture(void))"},
            &TaskListButton_OnDragCompletedGesture_Original,
            TaskListButton_OnDragCompletedGesture_Hook,
            true,
        },

        // Icon resolution
        {
            {LR"(public: double __cdecl winrt::Taskbar::implementation::TaskbarConfiguration::GetIconHeightInViewPixels(void))"},
            &TaskbarConfiguration_GetIconHeightInViewPixels_Original,
            TaskbarConfiguration_GetIconHeightInViewPixels_Hook,
            true,
        },
        {
            {LR"(public: struct winrt::Taskbar::implementation::TaskbarFrameMetrics __cdecl winrt::Taskbar::implementation::TaskbarFrame::GetMetrics(void)const )"},
            &TaskbarFrame_GetMetrics_Original,
            TaskbarFrame_GetMetrics_Hook,
            true,
        },
        {
            {LR"(public: void __cdecl winrt::Taskbar::implementation::TaskListButton::IconHeight(double))"},
            &TaskListButton_IconHeight_Address,
            nullptr,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateButtonPadding(void))"},
            &TaskListButton_UpdateButtonPadding_Original,
            TaskListButton_UpdateButtonPadding_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateVisualStates(void))"},
            &TaskListButton_UpdateVisualStates_Original,
            TaskListButton_UpdateVisualStates_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateIconColumnDefinition(void))"},
            &TaskListButton_UpdateIconColumnDefinition_Original,
            TaskListButton_UpdateIconColumnDefinition_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateMultiWindowClip(void))"},
            &TaskListButton_UpdateMultiWindowClip_Original,
            TaskListButton_UpdateMultiWindowClip_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::CreateMultiWindowClip(void))"},
            &TaskListButton_CreateMultiWindowClip_Original,
            TaskListButton_CreateMultiWindowClip_Hook,
            true,
        },
        {
            {LR"(private: void __cdecl winrt::Taskbar::implementation::TaskListButton::UpdateBadge(void))"},
            &TaskListButton_UpdateBadge_Original,
            TaskListButton_UpdateBadge_Hook,
            true,
        },
        {
            {LR"(public: void __cdecl winrt::Taskbar::implementation::TaskListButton::OverlayIcon(struct winrt::Windows::Storage::Streams::IRandomAccessStream const &))"},
            &TaskListButton_OverlayIcon_Original,
            TaskListButton_OverlayIcon_Hook,
            true,
        },
        {
            {LR"(public: double __cdecl winrt::Taskbar::implementation::ExperienceToggleButton::IconHeight(void)const )"},
            &ExperienceToggleButton_IconHeight_get,
            nullptr,
            true,
        },
        {
            {LR"(public: void __cdecl winrt::Taskbar::implementation::ExperienceToggleButton::IconHeight(double))"},
            &ExperienceToggleButton_IconHeight_Original,
            ExperienceToggleButton_IconHeight_Hook,
            true,
        },
        {
            {LR"(protected: virtual void __cdecl winrt::Taskbar::implementation::ExperienceToggleButton::UpdateButtonPadding(void))"},
            &ExperienceToggleButton_UpdateButtonPadding_Original,
            ExperienceToggleButton_UpdateButtonPadding_Hook,
            true,
        },
        {
            {LR"(public: void __cdecl winrt::Microsoft::Windows::Taskbar::implementation::TaskbarComponentHost::IconHeight(double))"},
            &TaskbarComponentHost_IconHeight_Original,
            TaskbarComponentHost_IconHeight_Hook,
            true,
        },
    };
    // On builds where the tray is in Taskbar.View.dll too, its hooks go in the
    // same call, so the module's symbols are only looked up once.
    std::vector<COMBINED_SH> allHooks(std::make_move_iterator(std::begin(taskbarViewHooks)),
                                      std::make_move_iterator(std::end(taskbarViewHooks)));
    if (withTray) {
        for (auto& hook : GetTrayHooks()) allHooks.push_back(std::move(hook));
    }
    if (!WindhawkUtils::HookSymbols(module, allHooks.data(), allHooks.size())) return false;
    if (TaskListButton_IconHeight_Address) GetIconHeightOffset();  // find it up front
    return true;
}

bool HookTraySymbols(HMODULE module) {
    auto systemTrayHooks = GetTrayHooks();
    return WindhawkUtils::HookSymbols(module, systemTrayHooks.data(), systemTrayHooks.size());
}

// Taskbar.View.dll before version 2604 contains the system tray too; newer
// builds moved it into SystemTray.dll.
bool TaskbarViewHasTray(HMODULE module) {
    HRSRC res = FindResource(module, MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION);
    HGLOBAL global = res ? LoadResource(module, res) : nullptr;
    void* data = global ? LockResource(global) : nullptr;
    VS_FIXEDFILEINFO* info = nullptr;
    UINT size = 0;
    if (!data || !VerQueryValue(data, L"\\", (void**)&info, &size) || !size) return false;
    return HIWORD(info->dwFileVersionMS) < 2604;
}

std::atomic<bool> g_taskbarViewHooked = false;
std::atomic<bool> g_trayHooked = false;

// Hooks whichever of the taskbar's DLLs are loaded and not hooked yet.
// Returns true if anything new was hooked.
bool HookTaskbarModules() {
    bool hooked = false;
    if (HMODULE view = GetModuleHandle(L"Taskbar.View.dll");
        view && !g_taskbarViewHooked.exchange(true)) {
        bool withTray = !GetModuleHandle(L"SystemTray.dll") && TaskbarViewHasTray(view) &&
                        !g_trayHooked.exchange(true);
        HookTaskbarViewSymbols(view, withTray);
        hooked = true;
    }
    if (HMODULE tray = GetModuleHandle(L"SystemTray.dll");
        tray && !g_trayHooked.exchange(true)) {
        HookTraySymbols(tray);
        hooked = true;
    }
    return hooked;
}

// The taskbar's DLLs load late when Explorer starts after the mod.
using LoadLibraryExW_t = decltype(&LoadLibraryExW);
LoadLibraryExW_t LoadLibraryExW_Original;
HMODULE WINAPI LoadLibraryExW_Hook(LPCWSTR name, HANDLE file, DWORD flags) {
    HMODULE module = LoadLibraryExW_Original(name, file, flags);
    if (module && (!g_taskbarViewHooked || !g_trayHooked) && HookTaskbarModules()) {
        Wh_ApplyHookOperations();
    }
    return module;
}

// ---------------------------------------------------------------------------
// Windhawk entry points
// ---------------------------------------------------------------------------

void LoadSettings() {
    g_dockSize = std::clamp(Wh_GetIntSetting(L"dock.size"), 0, 100);
    g_iconSpacingSetting = std::clamp(Wh_GetIntSetting(L"dock.iconSpacing"), 0, 50);
    auto color = WindhawkUtils::StringSetting::make(L"dock.color");
    g_dockTheme = wcscmp(color, L"dark") == 0 ? 1 : wcscmp(color, L"light") == 0 ? 2 : 0;
    auto style = WindhawkUtils::StringSetting::make(L"dock.style");
    g_dockStyle = wcscmp(style, L"highlights") == 0 ? 1 : 0;
    g_dockTint = std::clamp(Wh_GetIntSetting(L"dock.tint"), 0, 100);
    g_dockBlur = std::clamp(Wh_GetIntSetting(L"dock.blur"), 0, 100);
    g_dockBottomGapSetting = std::clamp(Wh_GetIntSetting(L"dock.bottomGap"), 0, 100);
    // Amount 0-100 -> the icon grows to 1.0x-2.0x.
    g_scale = 1.0f + std::clamp(Wh_GetIntSetting(L"magnification.amount"), 0, 100) / 100.0f;
    g_magnificationRange = std::clamp(Wh_GetIntSetting(L"magnification.range"), 0, 100);
    g_animationMs = std::clamp(Wh_GetIntSetting(L"magnification.smoothing"), 0, 1000);
    g_autoHideDock = Wh_GetIntSetting(L"behavior.autoHide");
    g_appsDivider = Wh_GetIntSetting(L"items.appsDivider");
    g_showTrash = Wh_GetIntSetting(L"items.recycleBin");
    g_showStart = Wh_GetIntSetting(L"items.startButton");
    g_hideTray = Wh_GetIntSetting(L"tray.hideTray");

    ComputeSizes();
    Wh_Log(L"Sizes: icon %.0f (loaded at %.0f), dock %.0f, taskbar %d, button margin %.1f",
           g_iconSize, g_iconLoadSize, g_dockHeight, g_taskbarHeight, g_buttonMargin);
}

BOOL Wh_ModInit() {
    LoadSettings();
    g_managingAutoHide = Wh_GetIntValue(UserValueName(L"managingAutoHide").c_str(), 0);
    g_autoHideBefore = Wh_GetIntValue(UserValueName(L"autoHideBefore").c_str(), 0);
    g_shellJobWork = CreateThreadpoolWork(RunShellJob, nullptr, nullptr);

    if (!HookTaskbarDllSymbols()) Wh_Log(L"taskbar.dll hooks failed; height won't change");
    HookTaskbarModules();

    if (HMODULE kb = GetModuleHandle(L"kernelbase.dll")) {
        if (auto p = GetProcAddress(kb, "LoadLibraryExW")) {
            WindhawkUtils::SetFunctionHook((LoadLibraryExW_t)p, LoadLibraryExW_Hook,
                                           &LoadLibraryExW_Original);
        }
    }

    // Hover name tooltips, and hover previews that are windows: move them down
    // to the dock when Explorer places them.
    WindhawkUtils::SetFunctionHook(SetWindowPos, SetWindowPos_Hook, &SetWindowPos_Original);
    WindhawkUtils::SetFunctionHook(DeferWindowPos, DeferWindowPos_Hook, &DeferWindowPos_Original);
    // Hover previews that are a XAML flyout: moved while their position is
    // worked out (see FlyoutFrame_UpdateFlyoutPosition_Hook).
    WindhawkUtils::SetFunctionHook(MapWindowPoints, MapWindowPoints_Hook, &MapWindowPoints_Original);
    return TRUE;
}

void Wh_ModAfterInit() {
    // Besides the height, this makes the taskbar update all its buttons, which
    // runs the hooks that find them (and the taskbars they're in).
    if (g_taskbarHeight > 0) ApplyTaskbarHeight();
    ApplyMagnifyOverWindows();
}

// Runs before the hooks are removed, which the taskbar needs to go back to its
// normal height and icon size.
void Wh_ModBeforeUninit() {
    // The hooks stay in place until after this; stop them from applying the
    // dock's changes again.
    g_unloading = true;

    // Undo the changes to the taskbar's elements first, so that when it goes
    // back to its normal size below, it sizes its icons itself, with nothing
    // of ours left to override that.
    if (HWND tb = FindTaskbar()) {
        RunFromWindowThread(tb, [](void*) { ResetAll(); }, nullptr);
    }
    ApplyAutoHide();  // back off, if the mod turned it on
    UnregisterClass(kWindowClass, ModuleInstance());
    // Shell jobs first: they end by checking the Recycle Bin.
    for (PTP_WORK* work : {&g_shellJobWork, &g_trashWork}) {
        if (!*work) continue;
        WaitForThreadpoolWorkCallbacks(*work, FALSE);
        CloseThreadpoolWork(*work);
        *work = nullptr;
    }

    if (g_taskbarHeight > 0) {
        g_taskbarHeight = 0;
        g_iconLoadSize = 0;
        ApplyTaskbarHeight();
    }
}

void Wh_ModSettingsChanged() {
    int oldTaskbarHeight = g_taskbarHeight;
    float oldIconLoadSize = g_iconLoadSize;
    // Settings are loaded on the taskbar thread, where the frame loop and hooks
    // read them. Plates (with the Recycle Bin) are rebuilt on the next frame,
    // and spacing and icon sizes are refreshed.
    HWND tb = FindTaskbar();
    bool ran = tb && RunFromWindowThread(tb, [](void*) {
            LoadSettings();
            try { RemovePlates(); } catch (...) {}
            try { StopTrash(); } catch (...) {}
            RestoreStartButtons();
            RestoreHiddenTrays();
            for (auto& b : *g_buttons) {
                if (auto el = b.element.get()) {
                    try {
                        ApplySpacing(el);
                        ApplyButtonWidth(b, el);
                        ApplyIconColumn(b);
                    } catch (...) {}
                }
            }
            for (auto& i : *g_iconImages) {
                if (auto el = i.element.get()) {
                    try { ApplyIconSize(el); } catch (...) {}
                }
            }
            for (auto& b : *g_badges) {
                auto el = b.element.get();
                auto panel = b.panel.get();
                if (el && panel) {
                    try { ApplyBadgePosition(el, panel); } catch (...) {}
                }
            }
            g_row.clear();  // rebuilt with the new spacing on next hover
            g_rowParent = nullptr;
            MarkPlatesDirty();
        }, nullptr);
    if (!ran) LoadSettings();
    if (g_taskbarHeight != oldTaskbarHeight || g_iconLoadSize != oldIconLoadSize) {
        ApplyTaskbarHeight();
    }
    ApplyMagnifyOverWindows();  // the dock's height may have changed too
}
