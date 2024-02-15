# Maintainer: Tola Mironcenko <mironcenkotola@gmail.com>
pkgname=pwdgen
pkgver=1.0
pkgrel=1
epoch=
pkgdesc=""
arch=('x86_64')
url=""
license=('GPL')
groups=()
depends=()
makedepends=()
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
noextract=()
md5sums=()
validpgpkeys=()
#source=("git+https://github.com/TolaMironcenko/pwdgen.git")

#prepare() {
#    cd $pkgname
#    mkdir -v out
#}

build() {
	#cd $pkgname
    cd $HOME/Documents/c/pwdgen
    [ ! -d out ] && mkdir out
    make
}

package() {
	#cd $pkgname
    cd $HOME/Documents/c/pwdgen
    mkdir -p $pkgdir/usr/local/bin
    make DESTDIR="$pkgdir/usr/local/bin/" install
}
