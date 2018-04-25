#!/bin/sh

case $1 in
	'apply')
		killall ovpn_sync_configs.sh
		/etc/openvpn/client/ovpn_sync_configs.sh &
		/usr/bin/openvpn_client.sh reconnect &
		;;
	'reconnect')
		sleep 2
		/usr/bin/openvpn_client.sh reconnect
		;;
esac

