---
title: Plugin: Linux Kernel Lockdown
---

## Introduction

This plugin checks if the currently running kernel is locked down. The result
will be stored in an security attribute for HSI.

## External Interface Access

This plugin requires read access to `/sys/sys/kernel/security`.
