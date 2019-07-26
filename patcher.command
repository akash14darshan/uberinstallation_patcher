#! /bin/bash
rm macpatch.zip
curl -LO https://github.com/akashdarshan99/uberinstallation_dir/raw/master/macpatch.zip
unzip macpatch.zip
username=$(id -un)
cp patch/uberdaemon /Users/$username/Library/Application\ Support/Steam/steamapps/common/Uberstrike
chmod +x /Users/$username/Library/Application\ Support/Steam/steamapps/common/Uberstrike/uberdaemon
cp -a patch/Data/. /Users/$username/Library/Application\ Support/Steam/steamapps/common/UberStrike/Uberstrike.app/Contents/Data
rm macpatch.zip
rm -rf patch