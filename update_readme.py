import json
import os

def generate_readme():
    readme_path = "README.md"
    day_map_file = "day_map.json"

    if not os.path.exists(day_map_file):
        print("❌ day_map.json not found!")
        return

    with open(day_map_file, "r", encoding="utf-8") as f:
        day_map = json.load(f)

    lines = []
    lines.append("# 📘 CODE_DIARY – My Daily DSA Practice\n\n")
    lines.append("This repository contains my daily DSA problem solutions grouped by day and topic.\n\n")
    lines.append("## 🗓️ Daily Progress\n")

    for day, files in day_map.items():
        lines.append(f"\n### 🗓️ {day}\n")
        lines.append("| 📁 Topic | 📄 Problem |\n")
        lines.append("|----------|------------|\n")

        for path in files:
            if os.path.exists(path):
                topic = path.split("/")[0]
                filename = path.split("/")[-1]
                url_path = path.replace(" ", "%20")
                lines.append(f"| {topic} | [{filename}]({url_path}) |\n")
            else:
                lines.append(f"| - | ⚠️ Missing: `{path}` |\n")

    with open(readme_path, "w", encoding="utf-8") as f:
        f.writelines(lines)

    print("✅ README.md updated based on day_map.json!")

if __name__ == "__main__":
    generate_readme()
