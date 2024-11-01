# Maintainer: Your Name <your.email@example.com>
pkgname=sf2player-reaper-plugin.cpp
pkgver=1.0.0
pkgrel=1
pkgdesc="A professional SF2 player plugin with GUI for Linux version of Reaper, built using JUCE and FluidSynth."
arch=('x86_64')
url="https://github.com/m20191201/sf2player-reaper-plugin"
license=('GPL')
depends=('fluidsynth' 'juce')
makedepends=('cmake' 'git')
source=("$pkgname::git+<your_github_repo_url>")
md5sums=('SKIP')

build() {
    cd "$srcdir/$pkgname"
    mkdir -p build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make
}

package() {
    cd "$srcdir/$pkgname/build"
    install -Dm755 sf2player-reaper-plugin.so "$pkgdir/usr/lib/vst3/sf2player-reaper-plugin.so"
}

# Optional: Add metadata to provide additional information
pkgver() {
    cd "$srcdir/$pkgname"
    git describe --tags | sed 's/^v//;s/-/./g'
}
