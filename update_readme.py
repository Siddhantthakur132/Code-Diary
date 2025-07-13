import os
import json

def generate_readme():
    day_map_path = "day_map.json"
    readme_path = "README.md"

    if not os.path.exists(day_map_path):
        print("❌ day_map.json not found!")
        return

    with open(day_map_path, "r", encoding="utf-8") as f:
        day_map = json.load(f)

    content = []
    content.append("# 📘 CODE_DIARY – My Daily DSA Practice\n")
    content.append("\nThis repository contains my daily DSA problem solutions grouped by day and topic.\n")
    content.append("\n## 📅 Daily Progress\n")

    for day, problems in day_map.items():
        content.append(f"\n### 🗓️ {day}\n")
        content.append("| 📁 Topic | 📄 Problem |\n")
        content.append("|-----------|-------------|\n")

        for path in problems:
            if not os.path.exists(path):
                continue
            topic = path.split("/")[0]
            file = path.split("/")[-1]
            url_path = path.replace(" ", "%20")
            content.append(f"| {topic} | [{file}]({url_path}) |\n")

    with open(readme_path, "w", encoding="utf-8") as f:
        f.writelines(content)

    print("✅ README.md updated with clean layout!")

if __name__ == "__main__":
    generate_readme()
