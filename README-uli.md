Ulis README.md
==============

DEB-Paket bauen
---------------

- Einmalig: Zusatzpakete installieren

  - Ubuntu: `sudo apt-get install -y g++ cmake make qtbase5-dev libqt5sql5-sqlite uuid-dev libcap-dev uuid-runtime linux-headers-generic dkms`
  - Ubuntu HWE: `sudo apt-get install -y g++ cmake make qtbase5-dev libqt5sql5-sqlite uuid-dev libcap-dev uuid-runtime linux-headers-generic-hwe-$(lsb_release -rs) dkms`

- [CMakeLists.txt](CMakeLists.txt) sichten

  - Passt shournal_version_base?
  - Passt shournal_version_suffix?

- `mkdir build`

- `cd build`

- `cmake -DSHOURNAL_EDITION=full -DCMAKE_INSTALL_PREFIX=/usr ..`

- `make`

- `cpack -G DEB` -> erzeugt shournal_3.1-0dp01~generic_amd64.deb

Neue Upstream-Version einbinden
-------------------------------

TBD
